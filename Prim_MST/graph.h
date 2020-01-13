#pragma once
#include <vector>
#include <unordered_map>
#include "edge.h"

class graph
{
public:
	edge operator ()(const char &i, const char &j) const;
	edge& operator ()(const char &i, const char &j);
	std::vector<std::pair<char, edge>> adjacent(const char &v) const;
	void dfs(std::unordered_map<char, bool> &visited, const char &current_vertex) const;
	bool is_connected() const;
	graph prim_mst(const char &starting_vertex) const;

	std::vector<char>	vertices;
	std::vector<edge>	edges;
};
