all: exec

mkdir_build:
	[ -d ./cmake-build-debug ] | mkdir -p cmake-build-debug

build: mkdir_build
	cd cmake-build-debug;cmake ..;make roguelike

exec: clean build
	./cmake-build-debug/src/roguelike

clean:
	rm -rf cmake-build-debug

osx_dep:
	brew install cmake cppcheck clang-format
	brew install ncurses spdlog
