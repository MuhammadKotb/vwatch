SOURCES:=src/*.cpp src/ui/*.cpp
MAKEFLAGS += --no-print-directory
CFLAGS+= -std=c++20
CFLAGS+= -D_REENTRANT  -I./include/ 
CFLAGS+= -L/usr/local/lib -Wl,-rpath,/usr/local/lib -Wl,--enable-new-dtags -lSDL2
CFLAGS+= -lavcodec
CFLAGS+= lib/*.o
CFLAGS+= -g -O0
CFLAGS+= -lGL
CFLAGS+= -ldl

build: 
	g++ $(SOURCES) -o src/main $(CFLAGS)
	@echo BuildSucc

run: build
	@src/main
