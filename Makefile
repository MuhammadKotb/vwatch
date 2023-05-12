SOURCES:=src/*.cpp
MAKEFLAGS += --no-print-directory
MAKEFLAGS += --no-print-directory

CFLAGS:=-std++20

build: 
	@g++ $(SOURCES) -o src/main
	@echo BuildSucc

run: build
	@src/main
