NAME := "eg"
# CPPFLAGS += "-Wno-c++11-extensions"
# STDVER := "-std=c++14"
STDVER := "-std=c++11"
PYBIND_INCLUDES := $(shell python3 -m pybind11 --includes)
PYBIND_EXTENSION := $(shell python3-config --extension-suffix)
EXTENSION := $(NAME)$(PYBIND_EXTENSION)

all: adaptagrams

adaptagrams:
	@c++ -O3 -Wall -shared $(STDVER) -fPIC \
		-undefined dynamic_lookup \
		$(PYBIND_INCLUDES) \
		-I ../include \
		pybind.cpp \
		../libs/libavoid.a \
		../libs/libcola.a \
		../libs/libdialect.a \
		../libs/libtopology.a \
		../libs/libvpsc.a \
		-o $(EXTENSION)

clean:
	@rm -f $(EXTENSION)
	@rm -rf .pytest_cache
	@rm -rf __pycache__


.PHONY: all clean

