from adaptagrams import Graph, DialectNode

def test_node():
    g = Graph()
    n = DialectNode.allocate(10.2, 3.4)
    g.addNode(n)
    assert g.getNumNodes() == 1
