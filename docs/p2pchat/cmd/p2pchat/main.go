package main

import (
	"log"
	"net/http"

	"p2pchat/internal/signaling"
)

func main() {

	hub := signaling.NewHub()

	go hub.Run()

	http.HandleFunc("/ws", func(w http.ResponseWriter, r *http.Request) {
		signaling.HandleWS(hub, w, r)
	})

	http.Handle("/", http.FileServer(http.Dir("./web/static")))

	log.Println("listen :8080")

	err := http.ListenAndServe(":8080", nil)
	if err != nil {
		panic(err)
	}
}
