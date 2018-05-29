all: exec

mkdir_build:
	[ -d ./build ] | mkdir -p build

build: mkdir_build
	cd build; cmake ..;make roguelike

exec: build
	./build/roguelike

osx_dep:
	brew install cmake ncurses cppcheck clang-format

.PHONY: mkdir_build