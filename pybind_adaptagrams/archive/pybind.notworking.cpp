#include <pybind11/pybind11.h>
#include <string.h>
#include "libdialect/graphs.h"
#include "libdialect/hola.h"


int add(int x, int y) {
    return x+y;
}

int add(int x, int y, int z) {
    return x+y+z;
}


void test_hola(void) {
    dialect::Graph g;
    g.addNode(10.2, 5.1);
    g.addNode(10.1, 5.5);
    g.addEdge(0, 1);
    doHOLA(g);
}

namespace py = pybind11;

template <typename... Args>
using overload_cast_ = pybind11::detail::overload_cast_impl<Args...>;

// typedef std::shared_ptr<dialect::Node> dialect::Node_SP;

    PYBIND11_MODULE(eg, m)
{
    m.doc() = "node example using pybind11.";

    // works
    // m.def("add", overload_cast_<int, int>()(&add), "add two ints");
    // m.def("add", overload_cast_<int, int, int>()(&add), "add three ints");

    // works
    // m.def("add", static_cast<int (*)(int, int)>(&add));
    // m.def("add", static_cast<int (*)(int, int, int)>(&add));

    // works c++14
    // m.def("add", py::overload_cast<int, int>(&add), "add two ints");
    // m.def("add", py::overload_cast<int, int, int>(&add), "add three ints");

    // Hola - not working
    // m.def("do_hola", overload_cast_<dialect::Graph, const dialect::HolaOpts, dialect::Logger>()(&dialect::doHOLA), "layout a graph with options");
    // m.def("do_hola", overload_cast_<dialect::Graph>()(&dialect::doHOLA), "layout a graph");

    // Hola - not working
    // m.def("do_hola", static_cast<void (*)(dialect::Graph, const dialect::HolaOpts, dialect::Logger)>(&dialect::doHOLA), "layout a graph with options");
    // m.def("do_hola", static_cast<void (*)(dialect::Graph)>(&dialect::doHOLA), "layout a graph");

    // Hola - working
    m.def("do_hola", static_cast<void (*)(dialect::Graph &g, const dialect::HolaOpts &h, dialect::Logger *l)>(&dialect::doHOLA), "layout a graph with options");
    m.def("do_hola", static_cast<void (*)(dialect::Graph &g)>(&dialect::doHOLA), "layout a graph");

    // Hola - not working
    // m.def("do_hola", overload_cast_<dialect::Graph &g, const dialect::HolaOpts &h, dialect::Logger *l>()(&dialect::doHOLA), "layout a graph with options");
    // m.def("do_hola", overload_cast_<dialect::Graph &g>()(&dialect::doHOLA), "layout a graph");

    // Hola - not working c++14
    // m.def("do_hola", py::overload_cast<dialect::Graph &g, const dialect::HolaOpts & h, dialect::Logger * l>(&dialect::doHOLA), "layout a graph with options");
    // m.def("do_hola", py::overload_cast<dialect::Graph &g>(&dialect::doHOLA), "add three ints");

    // Hola - works
    // m.def("do_hola", &dialect::doHOLA, "layout graph");

    //void doHOLA(dialect::Graph &G, const dialect::HolaOpts &holaOpts, dialect::Logger *logger = nullptr)
    // void doHOLA(dialect::Graph &G);

}
 
