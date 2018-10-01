all: lint build exec

mkdir_build: clean
	[ -d ./cmake-build-debug ] | mkdir -p cmake-build-debug

build: reload
	cd cmake-build-debug;make roguelike -j4

reload: mkdir_build
	cd cmake-build-debug;cmake ..

exec:
	./cmake-build-debug/src/roguelike

clean:
	rm -rf cmake-build-debug

fast_build:
	cd cmake-build-debug;make roguelike -j4

run: fast_build exec

debug-server: fast_build
	gdbserver :1234 ./cmake-build-debug/src/roguelike

osx_dep:
	brew install cmake cppcheck clang-format
	brew install ncurses log4cxx

lint:
	cd cmake-build-debug;make lint

reformat:
	clang-format -i -style=file include/roguelike/**/*.h
	clang-format -i -style=file src/**/*.cpp