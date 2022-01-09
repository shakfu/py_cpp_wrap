# py_cpp_wrap

This repo includes experiments in different ways of wrapping a large c++ library in python3.

The [adaptagrams](https://github.com/mjwybrow/adaptagrams) c++ library was used as the library to be wrapped. The compiled static lib files (compiled on 64bit macOS Catalina) and include files for the `adaptagrams` library as well as a compiled version of [binder](https://github.com/RosettaCommons/binder) are only included for convenience.

All rights reserved to the respective authors of the tools and libraries reviewed and used in this project.

**CAVEATS**: Please note that this repo contains experiements, incomplete experiments and snapshots of experiments. It probably contains bugs.

If you are interested in a `pybind11` wrapper of the hola library from [adaptagrams](https://github.com/mjwybrow/adaptagrams) then please see the [pyhola](https://github.com/shakfu/pyhola) project.

## Background

The reason this project came to light because I was looking for layout algorithms to automatically layout [Max/MSP](https://cycling74.com/products/max) patchers generated from my [py2max](https://github.com/shakfu/py2max) project and found the `adaptagrams` project to have a very promising algorithm which is explained in [this](https://skieffer.info/publications/kieffer2016hola.pdf) paper and which I wanted to test out.

Since `py2max` is written in python, I naturally gravitated towards the use of the python [SWIG](http://swig.org) extension provided by the authors of the adaptagrams library which I managed to compile and which worked quite well. Nonetheless, I found it difficult to make simple changes to the SWIG interface file which was used to wrap the adaptagrams library, and also found it quite difficult to get answers on how to make changes to the wrapper interface from the authors themselves and from anybody on Stackoverflow and the SWIG forums.

It turned out to be a nice opportunity to test other alternatives including [cython](http://cython.org) and [pybind11](https://pybind11.readthedocs.io/en/stable/) as well as [binder](https://github.com/RosettaCommons/binder) which is an automatic wrapping generator for pybind11.

## Preliminary Conclusions

It took me a couple of days to research, learn and generate a decent working wrapper for the HOLA part of the [libdialect](http://www.adaptagrams.org/documentation/libdialect.html) part of the adaptagrams library using a combination of `pybind11` and `binder`.

I didn't even need to try to wrap the library in Cython although I may do so one day to complete the experiment.

I gave up on SWIG since I couldn't get answers on some basic ways to extend the original interface file and just couldn't get it work after many many attempts.

My view is that if SWIG works it's like magic and you have a python extension in no time. But when it doesn't it's difficult to figure out why. There's a fascinating and instructive [post](https://code.activestate.com/lists/python-dev/109281) by the author of SWIG on the complexity which can result from trying to be 'magic'.
