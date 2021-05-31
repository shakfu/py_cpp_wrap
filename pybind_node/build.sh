c++ -O3 -Wall -shared -std=c++11 -fPIC \
    -undefined dynamic_lookup \
    $(python3 -m pybind11 --includes) \
    eg.cpp pybind.cpp \
    -o eg$(python3-config --extension-suffix)

