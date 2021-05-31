CPPFLAGS+="-Wno-c++11-extensions"

all: adaptagrams

adaptagrams_wrap.cxx: clean adaptagrams.i
	swig -Wall -DNDEBUG -c++ -python -I../include adaptagrams.i

adaptagrams: adaptagrams_wrap.cxx
	python3 setup.py build_ext --inplace

clean:
	@rm -f _adaptagrams.*
	@rm -f adaptagrams.py
	@rm -f adaptagrams_wrap.*
	@rm -rf build
	@rm -rf .pytest_cache
	@rm -rf __pycache__


.PHONY: all clean

