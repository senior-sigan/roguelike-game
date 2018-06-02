all: exec

mkdir_build:
	[ -d ./build ] | mkdir -p build

build: mkdir_build
	cd build;cmake ..;make game

exec: build
	./build/src/game/game

osx_dep:
	brew install cmake ncurses cppcheck clang-format

.PHONY: mkdir_build