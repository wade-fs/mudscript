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

mudscript:
	@ rm -f $(OUT)/$@ && mkdir -p $(OUT)
	@ TARGET=$@ CMD=$(basename $@) && \
	echo "TARGET=$@ CMD=$$CMD" && \
	go mod tidy && \
	env $(ENV) go build -o $(OUT)/$@ && \
	ls $(OUT)/$@ 

%:
	@ rm -f $(OUT)/$@ && mkdir -p $(OUT)
	@ TARGET=$@ CMD=$(basename $@) && \
	PLATFORM=$$(case $@ in *.exe) echo windows;; *) echo linux;; esac) && \
	echo "TARGET=$@ CMD=$$CMD build for $$PLATFORM" && \
	cd cmd/$@ && \
	go mod tidy && \
	env $(ENV) go build -o $(OUT)/$@ && \
	$(OUT)/$@ 

clean:
	@ rm -rf *.log $(OUT)/*
