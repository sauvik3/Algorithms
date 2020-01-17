#include "graph.h"
#include <algorithm>

edge graph::operator()(const char &v1, const char &v2) const
{
	edge res(v1, v2);
	if (v1 != v2)
	{
		const auto adjacent_edges = adjacent(v1);
		for (const auto edge_pair : adjacent_edges) {
			if (edge_pair.first == v2)
				return edge_pair.second;
		}
	}
	else
		res.weight = 0;
	return res;
}

edge& graph::operator()(const char &v1, const char &v2)
{
	const auto add_vertices = [this](const char &a, const char &b) {
		const auto itr = std::find(vertices_.begin(), vertices_.end(), a);
		if (itr == vertices_.end())
			vertices_.push_back(a);
		const auto itr1 = std::find(vertices_.begin(), vertices_.end(), b);
		if (itr1 == vertices_.end())
			vertices_.push_back(b);
	};

	edge res(v1, v2);
	if (v1 != v2)
	{
		const auto adjacent_edges = adjacent(v1);
		for (const auto edge_pair : adjacent_edges) {
			if (edge_pair.first == v2 && edge_pair.second.vertex1 == v1)
				return *std::find(edges_.begin(), edges_.end(), edge_pair.second);
		}
	}
	else
		res.weight = 0;
	add_vertices(v1, v2);
	edges_.push_back(res);
	return *(edges_.end() - 1);
}

std::vector<char> graph::get_vertices() const
{
	return vertices_;
}

std::vector<edge> graph::get_edges() const
{
	return edges_;
}

std::vector<std::pair<char, edge>> graph::adjacent(const char &v) const
{
	std::vector<std::pair<char, edge>> res;
	for (auto edge : edges_)
	{
		if (edge.vertex1 == v)
			res.push_back(std::make_pair(edge.vertex2, edge));
		else if (edge.vertex2 == v)
			res.push_back(std::make_pair(edge.vertex1, edge));
	}
	return res;
}

void graph::dfs(std::unordered_map<char, bool> &visited, const char &current_vertex) const
{
	visited[current_vertex] = true;
	auto adjacent_vertices = adjacent(current_vertex);
	for (const auto vertex : adjacent_vertices)
	{
		if (!visited[vertex.first])
			dfs(visited, vertex.first);
	}
}

bool graph::is_connected() const
{
	auto res = true;
	std::unordered_map<char, bool> visited;
	for (const auto vertex : vertices_)
		visited.insert(std::make_pair(vertex, false));

	if (visited.size() > 0)
		dfs(visited, visited.begin()->first);
	else
		res = false;

	for (const auto visit : visited)
		res = res && visit.second;

	return res;
}

char graph::min_key() const
{
	auto min = INT_MAX;
	char min_ver = 0;
	for (const auto vertex : visited_) {
		const auto wt = dist_table_[vertex.first];
		if (!vertex.second) {
			if (wt < min) {
				min_ver = vertex.first;
				min = wt;
			}
		}
	}
	return min_ver;
}

graph graph::prim_mst(const char &starting_vertex) const
{
	graph res;
	for (const auto vertex : vertices_) {
		visited_.insert(std::make_pair(vertex, false));
		dist_table_.insert(std::make_pair(vertex, INT_MAX));
	}
	dist_table_[starting_vertex] = 0;

	for (const auto v1 : vertices_)
	{
		auto min_ver = min_key();
		visited_[min_ver] = true;

		auto adjacent_edges = adjacent(min_ver);
		for (const auto current_edge : adjacent_edges)
		{
			if (current_edge.second.vertex1 == min_ver)
			{
				const auto current_vertex = current_edge.first;
				const auto current_wt = current_edge.second.weight;
				if (!visited_[current_vertex] || dist_table_[current_vertex] > current_wt)
				{
					dist_table_[current_vertex] = current_wt;
					res(current_edge.second.vertex1, current_edge.second.vertex2) = current_edge.second.weight;
				}
			}
		}
	}
	auto recurse = true;
	for (const auto visit : visited_) {
		recurse = recurse && visit.second;
		if(!recurse)
			break;
	}
	if(recurse)
		prim_mst(starting_vertex);

	return res;
}