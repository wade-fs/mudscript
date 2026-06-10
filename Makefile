#backend
DATE   := $(shell date +%Y%m%d)
USER := $(shell whoami)

COMMIT := $(shell git rev-parse --short=8 HEAD)
VERSION := $(COMMIT)-$(DATE)

TOP=$(shell pwd)
OUT=$(TOP)/bin

# 🚀 智慧路徑偵測：優先使用系統環境，找不到才用預設值
DETECTED_GOROOT := $(shell go env GOROOT 2>/dev/null)
GOROOT ?= $(DETECTED_GOROOT)
ifeq ($(GOROOT),)
    GOROOT := /usr/local/go-1.26.2
endif

# 🚀 根據 GOROOT 是否存在來決定 Go 執行檔路徑
GO_EXE := $(shell if [ -f $(GOROOT)/bin/go ]; then echo $(GOROOT)/bin/go; else echo go; fi)

# 環境變數配置 (移除強制 GOROOT 以相容 CI)
GO_FLAGS := -ldflags="-s -w"
COMMON_ENV := CGO_CFLAGS="-Wno-return-local-addr"
ENVW := $(COMMON_ENV) CGO_ENABLED=1 GOOS=windows GOARCH=amd64 CC="x86_64-w64-mingw32-gcc -fno-stack-protector -D_FORTIFY_SOURCE=0 -lssp"

.PHONY: all clean test test-driver test-fsmud fsmud fsmud.exe fs fs.exe mud-universal mud-universal.exe mudscript mudscript.exe run-fsmud run-fs push inject-hash

all: fsmud fsmud.exe fs fs.exe mud-universal mud-universal.exe mudscript mudscript.exe

inject-hash:
	@echo "Injecting HEAD hash $(COMMIT) into index.html..."
	@sed -i 's/Fantasy Space MUD.*</Fantasy Space MUD: $(COMMIT)</g' web/static/index.html

# 🚀 推送到 GitHub (乾淨的原始碼)
push-github:
	@echo "📤 Pushing to origin (GitHub)..."
	@git push origin main

# 🚀 推送到 HuggingFace
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

push: clean-txt push-github push-hf

$(OUT):
	@mkdir -p $(OUT)

# 編譯 Linux 版本
fsmud: $(OUT)
	@echo "🔨 Building $@ (Linux Standard)..."
	@go mod tidy && $(COMMON_ENV) $(GO_EXE) build $(GO_FLAGS) -tags fsmud -o $(OUT)/$@ ./cmd/fsmud
	@ls -l $(OUT)/$@

fs: $(OUT)
	@echo "🔨 Building $@ (Linux Legacy)..."
	@go mod tidy && $(COMMON_ENV) $(GO_EXE) build $(GO_FLAGS) -tags fs -o $(OUT)/$@ ./cmd/fsmud
	@ls -l $(OUT)/$@

mud-universal: $(OUT)
	@echo "🔨 Building $@ (Linux Universal)..."
	@go mod tidy && $(COMMON_ENV) $(GO_EXE) build $(GO_FLAGS) -tags universal -o $(OUT)/$@ ./cmd/fsmud
	@ls -l $(OUT)/$@

mudscript: $(OUT)
	@echo "🔨 Building $@ (Linux Pure)..."
	@go mod tidy && $(COMMON_ENV) $(GO_EXE) build $(GO_FLAGS) -o $(OUT)/$@ ./cmd/fsmud
	@ls -l $(OUT)/$@

# 編譯 Windows 版本 (.exe)
fsmud.exe: $(OUT)
	@echo "🔨 Building $@ (Windows Standard)..."
	@go mod tidy && $(ENVW) $(GO_EXE) build $(GO_FLAGS) -tags fsmud -o $(OUT)/$@ ./cmd/fsmud
	@ls -l $(OUT)/$@

fs.exe: $(OUT)
	@echo "🔨 Building $@ (Windows Legacy)..."
	@go mod tidy && $(ENVW) $(GO_EXE) build $(GO_FLAGS) -tags fs -o $(OUT)/$@ ./cmd/fsmud
	@ls -l $(OUT)/$@

mud-universal.exe: $(OUT)
	@echo "🔨 Building $@ (Windows Universal)..."
	@go mod tidy && $(ENVW) $(GO_EXE) build $(GO_FLAGS) -tags universal -o $(OUT)/$@ ./cmd/fsmud
	@ls -l $(OUT)/$@

mudscript.exe: $(OUT)
	@echo "🔨 Building $@ (Windows Pure)..."
	@go mod tidy && $(ENVW) $(GO_EXE) build $(GO_FLAGS) -o $(OUT)/$@ ./cmd/fsmud
	@ls -l $(OUT)/$@

# 執行測試
test-driver: mudscript
	@echo "🧪 Running MudScript Core Tests on driver in isolation..."
	@MUD_TEST_MODE=1 $(OUT)/mudscript -mudlib testlib -master master.c --hub none 2>&1 | tee test-driver.txt

test: test-driver

# 正常執行伺服器
run-fsmud: fsmud
	@echo "🚀 Starting MudScript Server (Connecting to Global Hub)..."
	@ ./bin/fsmud -mudlib fsmud -master master.c 2>&1 | tee run-fsmud.txt

# 正常執行 Legacy FS 伺服器
run-fs: fs
	@echo "🚀 Starting Legacy FS MudScript Server..."
	@ ./bin/fs -mudlib fs -master /adm/obj/master.c -legacy 2>&1 | tee run-fs.txt

# 執行 Legacy FS 登入測試
test-fs: fs
	@echo "🧪 Running Connection & Login Test on Legacy FS..."
	@go run ./cmd/test-fs/main.go 2>&1 | tee test-fs.txt

# 執行 FSMUD 自動化一鍵整合測試
test-fsmud: fsmud
	@echo "🧪 Running Integration Test on FSMUD..."
	@go run ./cmd/test-fsmud/main.go


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
