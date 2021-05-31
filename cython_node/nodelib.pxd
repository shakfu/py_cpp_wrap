from libcpp.pair cimport pair

cdef extern from "eg.cpp":
    pass

cdef extern from "eg.h":
    cdef cppclass Node:
        Node() except +
        double width, height

        void setHeight(double height)
        double getHeight()

        void setWidth(double width)
        double getWidth()

        void setDimensions(double h, double w)
        pair[double, double] getDimensions()

