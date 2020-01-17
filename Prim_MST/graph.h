#pragma once
#include <vector>
#include <unordered_map>
#include "edge.h"

class graph
{
public:
	edge operator ()(const char &i, const char &j) const;
	edge& operator ()(const char &i, const char &j);
	std::vector<char> get_vertices() const;
	std::vector<edge> get_edges() const;

	std::vector<std::pair<char, edge>> adjacent(const char &v) const;
	void dfs(std::unordered_map<char, bool> &visited, const char &current_vertex) const;
	bool is_connected() const;
	graph prim_mst(const char &starting_vertex) const;

private:
	char min_key() const;

	std::vector<char>	vertices_;
	std::vector<edge>	edges_;
	mutable std::unordered_map<char, int> dist_table_;
	mutable std::unordered_map<char, bool> visited_;
};
