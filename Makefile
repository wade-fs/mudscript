#backend
DATE   := $(shell date +%Y%m%d)
USER := $(shell whoami)

COMMIT := $(shell git rev-parse --short=8 HEAD)
VERSION := $(COMMIT)-$(DATE)

TOP=$(shell pwd)
OUT=$(TOP)/bin
GOPATH := $(HOME)/go-1.26.2
GOROOT := /usr/local/go-1.26.2
GO_FLAGS := -ldflags="-s -w"

ENV  := GOPATH=$(GOPATH) GOROOT=$(GOROOT) CGO_CFLAGS="-Wno-return-local-addr"
ENVW := $(ENV) CGO_ENABLED=1 CGO_CFLAGS="-Wno-return-local-addr" GOOS=windows GOARCH=amd64 CC="x86_64-w64-mingw32-gcc -fno-stack-protector -D_FORTIFY_SOURCE=0 -lssp"

.PHONY: all clean test fsmud fsmud.exe run

all: fsmud fsmud.exe

# 建立編譯目錄
$(OUT):
	@mkdir -p $(OUT)

# 編譯 Linux 版本 (不自動執行)
fsmud: $(OUT)
	@echo "🔨 Building Linux version..."
	@export $(ENV) && go mod tidy && $(GOROOT)/bin/go build $(GO_FLAGS) -o $(OUT)/fsmud ./cmd/fsmud
	@ls -l $(OUT)/fsmud

# 編譯 Windows 版本
fsmud.exe: $(OUT)
	@echo "🔨 Building Windows version..."
	@export $(ENVW) && go mod tidy && $(GOROOT)/bin/go build $(GO_FLAGS) -o $(OUT)/fsmud.exe ./cmd/fsmud
	@ls -l $(OUT)/fsmud.exe

# 執行測試
test: fsmud
	@echo "🧪 Running MudScript Core Tests..."
	@MUD_TEST_MODE=1 $(OUT)/fsmud

# 正常執行伺服器
run: fsmud
	@echo "🚀 Starting MudScript Server..."
	@$(OUT)/fsmud

clean:
	@rm -rf *.log $(OUT)/*
