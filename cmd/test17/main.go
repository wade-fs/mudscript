package main

import (
	"mudscript/driver"
	"mudscript/net"
)

func main() {
	// 1. 初始化 Driver 與 Master
	d := driver.New(driver.DriverConfig{
        MudLibPath: "./mudlib-from-claude",
        MasterFile: "/master.c",
    })
	
	if err := d.Start(); err != nil {
        panic(err)
    }

	// 2. 啟動網路服務
	server := net.NewServer(4000, d)
	server.Listen()
}
