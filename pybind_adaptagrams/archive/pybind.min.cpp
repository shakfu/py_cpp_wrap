#include <string.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "libdialect/graphs.h"
#include "libdialect/hola.h"
#include "libdialect/io.h"

namespace py = pybind11;

using namespace dialect;
using namespace pybind11::literals;

template <typename... Args>
using overload_cast_ = pybind11::detail::overload_cast_impl<Args...>;


PYBIND11_MODULE(eg, m)
{
    m.doc() = "adaptagrams library wrapper using pybind11.";
    m.attr("__version__") = "0.0.1";

    m.def("graph_from_tglf_file", &buildGraphFromTglfFile, "build graph from .tglf file");

    m.def("do_hola", static_cast<void (*)(Graph &g, const HolaOpts &h, Logger *l)>(&doHOLA), "layout a graph with options");
    m.def("do_hola", static_cast<void (*)(Graph &g)>(&doHOLA), "layout a graph");

    // py::class_<Graph>(m, "Graph")
    py::class_<Graph, Graph_SP>(m, "Graph")
        .def(py::init<>())
        .def("get_num_nodes", &Graph::getNumNodes, "get number of nodes")
        .def("get_num_edges", &Graph::getNumEdges, "get number of edges")
        .def("get_max_degree", &Graph::getMaxDegree, "get maximum degree of graph")

        // nodes
        .def("add_node", overload_cast_<Node_SP, bool>()(&Graph::addNode), "add node", "node"_a, "take_ownership"_a = true)
        .def("add_node", overload_cast_<double, double>()(&Graph::addNode), "add node (w, h)")
        .def("add_node", overload_cast_<double, double, double, double>()(&Graph::addNode), "add node (x, y, w, h)")

        // edges
        .def("add_edge", overload_cast_<Edge_SP, bool>()(&Graph::addEdge), "add edge from edge instance", "edge"_a, "take_ownership"_a = true)
        .def("add_edge", overload_cast_<Node_SP, Node_SP>()(&Graph::addEdge), "add edge from (src node, dst node)")
        //.def("add_edge", overload_cast_<const id_type, const id_type>()(&Graph::addEdge), "add edge from (src node, dst node)")
        //.def("add_edge", static_cast<Edge_SP (*)(const id_type &srcID, const id_type &dstID)>(&Graph::addEdge), "add edge from (src node, dst node)")

        // utility methods
        .def("has_node", &Graph::hasNode, "returns true if node id is in graph")
        .def("has_edge", &Graph::hasEdge, "returns true if edge id is in graph")
        .def("sever_node", &Graph::severNode, "sever node from graph")
        .def("sever_edge", &Graph::severEdge, "sever edge from graph")
        .def("remove_node", &Graph::removeNode, "remove node from graph")
        .def("remove_edge", &Graph::removeNodes, "remove nodes from graph")
        .def("get_node", &Graph::getNode, "get node from id")
        .def("get_nodemap", &Graph::getNodeLookup, "get map of nodes by id")

        // write methods
        .def("to_tglf", &Graph::writeTglf, "returns tglf string", "use_external_ids"_a = false)
        .def("to_svg", &Graph::writeSvg, "returns svg string", "use_external_ids"_a = false)
        ;

    py::class_<Node, Node_SP>(m, "Node")
        .def_static("allocate", overload_cast_<double, double>()(&Node::allocate), "allocate width, height", "w"_a, "h"_a)
        .def_static("allocate", overload_cast_<double, double, double, double>()(&Node::allocate), "allocate width, height", "x"_a, "y"_a, "w"_a, "h"_a)
        .def_property_readonly("id", &Node::id, "retrieve node id")

        .def("get_dimensions", &Node::getDimensions, "return width and height")
        .def("get_degree", &Node::getDegree, "return node degree")
        .def("set_centre", &Node::setCentre, "set centre pos", "cx"_a, "cy"_a = 10)
        .def("translate", &Node::translate, "adjust centre pos", "dx"_a, "dy"_a);

    py::class_<Edge, Edge_SP>(m, "Edge")
        .def("allocate", &Edge::allocate, "allocate edge from src node to dst node")
        ;
}
 
