#pragma once
#include <vector>
#include <unordered_map>
#include "edge.h"

class graph_
{
public:
	edge operator ()(const char &i, const char &j) const;
	edge& operator ()(const char &i, const char &j);
	std::vector<std::pair<char, edge>> adjacent(char v) const;
	void dfs(std::unordered_map<char, bool> &visited, char current_vertex) const;
	bool is_connected();

	std::vector<char>	vertices;
	std::vector<edge>	edges;
};
