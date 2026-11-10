# 1. Build Stage
FROM golang:1.26-alpine AS builder

WORKDIR /app

# 安裝編譯所需的工具
RUN apk add --no-cache make git

# 複製依賴文件
COPY go.mod go.sum ./
RUN go mod download

# 複製源碼
COPY . .

# 編譯 Linux 純淨版驅動 (bin/mudscript)
RUN make mudscript

# 2. Final Stage
FROM alpine:latest

WORKDIR /app

# 安裝運行時必要的套件
RUN apk add --no-cache libc6-compat ca-certificates

# 從 Build Stage 複製編譯好的執行檔 bin/mudscript 與兩個世界 (fs & forgotten-space)
COPY --from=builder /app/bin/mudscript /app/bin/mudscript
COPY --from=builder /app/fs /app/fs
COPY --from=builder /app/forgotten-space /app/forgotten-space

# 建立啟動腳本：同時啟動 fs (port 4000) 與 forgotten-space (port 7864)
RUN printf '#!/bin/sh\n\
echo "🚀 Starting Legacy FS on port 4000..."\n\
./bin/mudscript -mudlib fs -master /adm/obj/master.c -legacy --port 4000 &\n\
echo "🚀 Starting Forgotten Space on port 7864..."\n\
./bin/mudscript -mudlib forgotten-space -master master.c --port 7864 &\n\
wait -n\n\
exit $?\n' > /app/start.sh && chmod +x /app/start.sh

# 開放 4000 (fs) 與 7864 (forgotten-space) 連接埠
EXPOSE 4000 7864

# 啟動雙世界服務
CMD ["/app/start.sh"]

