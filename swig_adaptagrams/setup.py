#!/usr/bin/env python

"""
setup.py file for SWIG example
"""

from distutils.core import setup, Extension
from distutils import util

platform = util.get_platform()

adaptagrams_module = Extension(
    "_adaptagrams",
    sources=["adaptagrams_wrap.cxx"],
    extra_compile_args=[
        "-DUSE_ASSERT_EXCEPTIONS",
        "-DSWIG_PYTHON_SILENT_MEMLEAK",
        "-std=gnu++11",
        "-stdlib=libc++",
    ],

    include_dirs=["../include"],
    extra_link_args=[
        "../libs/libcola.a",
        "../libs/libtopology.a",
        "../libs/libavoid.a",
        "../libs/libvpsc.a",
        "../libs/libdialect.a",
    ],
)

setup(
    name="adaptagrams",
    version="0.1",
    author="MArVL",
    description="""Adaptagrams libraries""",
    ext_modules=[adaptagrams_module],
    py_modules=["adaptagrams"],
)
