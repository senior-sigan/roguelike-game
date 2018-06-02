all: exec

mkdir_build:
	[ -d ./cmake-build-debug ] | mkdir -p cmake-build-debug

build: mkdir_build
	cd cmake-build-debug;cmake ..;make game

exec: clean build
	./cmake-build-debug/src/game/game

clean:
	rm -rf cmake-build-debug

osx_dep:
	brew install cmake ncurses cppcheck clang-format