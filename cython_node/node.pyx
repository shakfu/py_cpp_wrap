# distutils: language = c++

from nodelib cimport Node as CNode


cdef class Node:
    cdef CNode c_node

    def __cinit__(self):
        self.c_node = CNode()

    def get_height(self):
        return self.c_node.getHeight()

    def set_height(self, double h):
        self.c_node.setHeight(h)

    def get_width(self):
        return self.c_node.getWidth()

    def set_width(self, double w):
        self.c_node.setWidth(w)

    def get_dimensions(self):
        return self.c_node.getDimensions()

    def set_dimensions(self, h, w):
        self.c_node.setDimensions(h, w)

    # Attribute access
    @property
    def height(self):
        return self.get_height()
    
    @height.setter
    def height(self, h):
        self.set_height(h)

    @property
    def width(self):
        return self.get_width()
    
    @width.setter
    def width(self, w):
        self.set_width(w)