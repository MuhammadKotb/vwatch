SOURCES:=src/*.cpp
MAKEFLAGS += --no-print-directory
CFLAGS+= -std=c++20
CFLAGS+= -D_REENTRANT -I/usr/local/include -I/usr/local/include/SDL2 -I./include/ -I./include/imgui
CFLAGS+= -L/usr/local/lib -Wl,-rpath,/usr/local/lib -Wl,--enable-new-dtags -lSDL2

build: 
	g++ $(SOURCES) -o src/main $(CFLAGS)
	@echo BuildSucc

run: build
	@src/main
