#include "edge.h"
#include "graph.h"

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
	g.print_matrix();

	return 0;
}
