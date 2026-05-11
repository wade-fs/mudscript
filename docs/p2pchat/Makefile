APP=p2pchat

build: tidy
	go build -o ./bin/$(APP) ./cmd/p2pchat

stun-test:
	@ cd cmd/$@ && go mod tidy && go build -o ../../bin/$@ .

run:
	go run ./cmd/p2pchat

clean:
	rm -rf ./bin

tidy:
	go mod tidy
