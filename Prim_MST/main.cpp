#include "graph.h"
#include "graph_utils.h"
#include <iostream>

int main()
{
	graph g;
	g('a', 'b') = 4;
	g('a', 'f') = 2;
	g('f', 'b') = 3;
	g('c', 'b') = 6;
	g('c', 'f') = 1;
	g('f', 'e') = 4;
	g('d', 'e') = 2;
	g('d', 'c') = 3;

	std::cout << std::endl;
	std::cout << "Original Graph : " << std::endl;
	print_table(g);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "MST Graph : " << std::endl;
	const auto mst = g.prim_mst('a');
	print_table(mst);
	std::cout << std::endl;

	return 0;
}
