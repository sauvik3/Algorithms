#pragma once
#include "graph_.h"

/* Use ASCII Box-Drawing Characters */

#define LLCNR 0xC0   /* ? */
#define LUCNR 0xDA   /* ? */
#define RLCNR 0xD9   /* ? */
#define RUCNR 0xBF   /* ? */
#define VRT   0xB3   /* ? */

class graph : public graph_
{
public:
	void print_matrix();
};
