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

all: fsmud.exe fsmud

# 通用規則
%:
	@ rm -f $(OUT)/$@ && mkdir -p $(OUT)
	@ if [ "$(suffix $@)" = ".exe" ]; then \
		echo ENVVAR=$(ENVW) BASE=$(basename $@); \
		export ENVVAR=$(ENVW) BASE=$(basename $@); \
		go mod tidy && \
		$(GOROOT)/bin/go build $(GO_FLAGS) -o $(OUT)/$@ ./cmd/$$BASE && \
		ls $(OUT)/$@; \
	else \
		echo ENVVAR=$(ENV) BASE=$(basename $@); \
		export ENVVAR=$(ENV) BASE=$(basename $@); \
		go mod tidy && \
		$(GOROOT)/bin/go build $(GO_FLAGS) -o $(OUT)/$@ ./cmd/$@ && \
		ls $(OUT)/$@ && \
		$(OUT)/$@; \
	fi

clean:
	@ rm -rf *.log $(OUT)/*
