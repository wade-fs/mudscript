#backend
DATE   := $(shell date +%Y%m%d)
USER := $(shell whoami)

COMMIT := $(shell git rev-parse --short=8 HEAD)
VERSION := $(COMMIT)-$(DATE)

TOP=$(shell pwd)
OUT=$(TOP)/bin
GOPATH := $(HOME)/go-1.26.2
GOROOT := /usr/local/go-1.26.2
GO_FLAGS := -ldflags="-s -w -X main.Version=$(VERSION)"

ENV := GOPATH=$(GOPATH) GOROOT=$(GOROOT)

all: fsmud.exe fsmud

# 通用規則
%.exe:
	@ rm -f $(OUT)/$@ && mkdir -p $(OUT)
	@ BASE=$(basename $@); \
	go mod tidy && \
	env $(ENV) GOOS=windows go build $(GO_FLAGS) -o $(OUT)/$@ ./cmd/$$BASE && \
	ls $(OUT)/$@

%:
	@ rm -f $(OUT)/$@ && mkdir -p $(OUT)
	@ go mod tidy && \
	env $(ENV) go build $(GO_FLAGS) -o $(OUT)/$@ ./cmd/$@ && \
	ls $(OUT)/$@ && \
	$(OUT)/$@

clean:
	@ rm -rf *.log $(OUT)/*
