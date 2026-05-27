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

.PHONY: all clean test fsmud fsmud.exe run push inject-hash

all: fsmud fsmud.exe

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
fsmud: $(OUT)
	@echo "🔨 Building Linux version..."
	@go mod tidy && $(GO_EXE) build $(GO_FLAGS) -o $(OUT)/fsmud ./cmd/fsmud
	@ls -l $(OUT)/fsmud

# 編譯 Windows 版本
fsmud.exe: $(OUT) inject-hash
	@echo "🔨 Building Windows version..."
	@go mod tidy && $(GO_EXE) build $(GO_FLAGS) -o $(OUT)/fsmud.exe ./cmd/fsmud
	@ls -l $(OUT)/fsmud.exe

# 執行測試 (測試模式下不連接 P2P 以免干擾)
test: fsmud
	@echo "🧪 Running MudScript Core Tests..."
	@MUD_TEST_MODE=1 $(OUT)/fsmud --hub none

# 正常執行伺服器 (預設連接全球星際中心)
run: fsmud
	@echo "🚀 Starting MudScript Server (Connecting to Global Hub)..."
	@ $(OUT)/fsmud 2>&1 | tee run.txt

run-clean: fsmud
	@echo "🚀 Starting MudScript Server (Connecting to Global Hub)..."
	@ rm -rf mudlib/data/user/*
	@$(OUT)/fsmud --hub wss://wade-fs-fsmud-hub.hf.space/ws 2>&1 | tee run-clean.txt

clean:
	@rm -rf *.log $(OUT)/*

zip:
	@ mv .git ../GIT
	@ rm -f bin/fsmud mudscript.zip
	@ zip -r mudscript driver object web mudlib/npc mudlib/cmds/admin mudlib/std mudlib/secure mudlib/include mudlib/cmds/cmd_lm.c mudlib/cmds/cmd_mc.c mudlib/cmds/cmd_fs* cmd/fsmud/main.go mudlib/proxy/
	@ mv ../GIT .git
	@ ls -l mudscript.zip
