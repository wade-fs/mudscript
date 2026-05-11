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

all: mudscript

mudscript:
	@ rm -f $(OUT)/$@ && mkdir -p $(OUT)
	@ go mod tidy && \
	env $(ENV) go build -o $(OUT)/$@ && \
	ls $(OUT)/$@ 

p2pchat:
	@ rm -f $(OUT)/$@ && mkdir -p $(OUT)
	@ cd cmd/$@ && go mod tidy && \
	env $(ENV) go build -o $(OUT)/$@ && \
	ls $(OUT)/$@ 

%:
	@ rm -f $(OUT)/$@ && mkdir -p $(OUT)
	@ cd cmd/$@ && \
	go mod tidy && \
	env $(ENV) go build -o $(OUT)/$@ && \
	cd $(TOP) && \
	$(OUT)/$@ 

clean:
	@ rm -rf *.log $(OUT)/*
