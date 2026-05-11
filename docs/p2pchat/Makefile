APP=p2pchat

build: tidy
	go build -o ./bin/$(APP) ./cmd/p2pchat

run:
	go run ./cmd/p2pchat

clean:
	rm -rf ./bin

tidy:
	go mod tidy
