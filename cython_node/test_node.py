
from node import Node


def test_node():
    n = Node()
    n.set_dimensions(10.2, 5.5)
    first, second = n.get_dimensions()

    assert first == 10.2
    assert second == 5.5

if __name__ == '__main__':
    test_node()
