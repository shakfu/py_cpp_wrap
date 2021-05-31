#include <pybind11/pybind11.h>
#include <string.h>
#include "eg.h"

namespace py = pybind11;

PYBIND11_MODULE(eg, m)
{
    m.doc() = "node example using pybind11.";

    py::class_<Node>(m, "Node")
        .def(py::init<>())
        .def("set_height", &Node::setHeight, "set node height")
        .def("get_height", &Node::getHeight, "get node height")
        .def("set_width", &Node::setWidth, "set node width")
        .def("get_width", &Node::getWidth, "get node width");
}

