#backend
DATE   := $(shell date +%Y%m%d)
USER := $(shell whoami)

COMMIT := $(shell git rev-parse --short=8 HEAD)
VERSION := $(COMMIT)-$(DATE)

TOP=$(shell pwd)
OUT=$(TOP)/bin
GOPATH ?= $(HOME)/go-1.26.2
GOROOT ?= /usr/local/go-1.26.2
GO_FLAGS := -ldflags="-s -w"

# 🚀 根據 GOROOT 是否存在來決定 Go 執行檔路徑
GO_EXE := $(shell if [ -f $(GOROOT)/bin/go ]; then echo $(GOROOT)/bin/go; else echo go; fi)

ENV  := GOPATH=$(GOPATH) GOROOT=$(GOROOT) CGO_CFLAGS="-Wno-return-local-addr"
ENVW := $(ENV) CGO_ENABLED=1 CGO_CFLAGS="-Wno-return-local-addr" GOOS=windows GOARCH=amd64 CC="x86_64-w64-mingw32-gcc -fno-stack-protector -D_FORTIFY_SOURCE=0 -lssp"

.PHONY: all clean test-fsmud fsmud fsmud.exe fs fs.exe run push inject-hash

all: fsmud fsmud.exe fs fs.exe

inject-hash:
	@echo "Injecting HEAD hash $(COMMIT) into index.html..."
	@sed -i 's/Fantasy Space MUD.*</Fantasy Space MUD: $(COMMIT)</g' web/static/index.html

# 🚀 推送到 GitHub (乾淨的原始碼)
push-github:
	@echo "📤 Pushing to origin (GitHub)..."
	@git push origin main

# 🚀 推送到 HuggingFace (強制寫入官方 fantasy.space 識別字與 wade.o 存檔)
push-hf:
	@echo "📤 Pushing to hf (HuggingFace)..."
	@echo '{"mudlib_id":"fantasy.space","mudlib_name":"fantasy space"}' > mudlib/data/system.o
	@git checkout -B hf-deploy
	@-if [ -f mudlib/data/user/wade.o ]; then git add mudlib/data/user/wade.o -f; fi
	@git add mudlib/data/system.o -f
	@git commit -m "Deploy to HF with official identity and local data" || true
	@git push hf hf-deploy:main --force
	@git checkout main

clean-txt:
	@ rm -f *txt *log

# 🚀 一鍵雙推
push: clean-txt push-github push-hf

# 建立編譯目錄

$(OUT):
	@mkdir -p $(OUT)

# 編譯 Linux 版本 (不自動執行)
# fsmud: $(OUT) inject-hash
fsmud fsmud.exe fs fs.exe: $(OUT)
	@echo "🔨 Building $@..."
	@go mod tidy && $(GO_EXE) build $(GO_FLAGS) -o $(OUT)/$@ ./cmd/$@
	@ls -l $(OUT)/$@

# 執行測試 (測試模式下不連接 P2P 以免干擾)
test-fsmud: fsmud
	@echo "🧪 Running MudScript Core Tests on fsmud/ mudlib..."
	@MUD_TEST_MODE=1 $(OUT)/fsmud --hub none 2>&1 | tee /tmp/test.txt

# 正常執行伺服器 (預設連接全球星際中心)
run-fsmud: fsmud
	@echo "🚀 Starting MudScript Server (Connecting to Global Hub)..."
	@ $(OUT)/fsmud 2>&1 | tee /tmp/run-fsmud.txt

# 正常執行 Legacy FS 伺服器
run-fs: fs
	@echo "🚀 Starting Legacy FS MudScript Server..."
	@ $(OUT)/fs 2>&1 | tee /tmp/run-fs.txt

clean:
	@rm -rf *.log *txt $(OUT)/*

zip:
	@ rm -f bin/fsmud mudscript.zip
	@ zip -r mudscript driver object web mudlib/npc mudlib/cmds/admin mudlib/std mudlib/secure mudlib/include mudlib/cmds/cmd_lm.c mudlib/cmds/cmd_mc.c mudlib/cmds/cmd_fs* cmd/fsmud/main.go
	@ ls -l mudscript.zip

zip-fs:
	@ rm -f bin/fs mudscript.zip
	@ zip -r mudscript driver object preprocessor fs/adm 
	@ ls -l mudscript.zip
