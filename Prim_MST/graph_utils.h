#pragma once
#include "graph.h"

#define INF   "-"   /* ? */

/* Use ASCII Box-Drawing Characters */

#define LLCNR 0xC0   /* ? */
#define LUCNR 0xDA   /* ? */
#define RLCNR 0xD9   /* ? */
#define RUCNR 0xBF   /* ? */
#define VRT   0xB3   /* ? */
#define HOR   0xC4   /* ? */
#define CEN   0xC5   /* ? */

void print_table(const graph &gph, bool sort_vertices = true);