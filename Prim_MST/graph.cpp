#include "graph.h"
#include <algorithm>

edge graph::operator()(const char & i, const char & j) const
{
	edge res(i, j);
	if (i != j)
	{
		auto adjacent_edges = adjacent(i);
		for (const auto edge_pair : adjacent_edges) {
			if (edge_pair.second.vertex2 == j)
				return edge_pair.second;
		}
	}
	else
		res.weight = 0;
	return res;
}

edge & graph::operator()(const char & i, const char & j)
{
	const auto add_vertices = [this](const char a, const char b)
	{
		const auto itr = std::find(vertices.begin(), vertices.end(), a);
		if (itr == vertices.end())
			vertices.push_back(a);
		const auto itr1 = std::find(vertices.begin(), vertices.end(), b);
		if (itr1 == vertices.end())
			vertices.push_back(b);
	};
	edge res(i, j);
	if (i != j)
	{
		auto adjacent_edges = adjacent(i);
		for (const auto edge_pair : adjacent_edges) {
			if (edge_pair.second.vertex2 == j)
			{
				const auto itr = std::find(edges.begin(), edges.end(), edge_pair.second);
				if (itr != edges.end())
					return *itr;
				else
				{
					const edge new_edge(i, j);
					edges.push_back(new_edge);
					add_vertices(i, j);
					return *(edges.end() - 1);
				}
			}
		}
	}
	else
		res.weight = 0;
	add_vertices(i, j);
	edges.push_back(res);
	return *(edges.end() - 1);
}

std::vector<std::pair<char, edge>> graph::adjacent(const char &v) const
{
	std::vector<std::pair<char, edge>> res;
	for (auto edge : edges)
	{
		if (edge.vertex1 == v)
			res.push_back(std::make_pair(edge.vertex2, edge));
		else if (edge.vertex2 == v)
			res.push_back(std::make_pair(edge.vertex1, edge));
	}
	return res;
}

void graph::dfs(std::unordered_map<char, bool>& visited, const char &current_vertex) const
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
	for (const auto vertex : vertices)
		visited.insert(std::make_pair(vertex, false));

	if (visited.size() > 0)
		dfs(visited, visited.begin()->first);
	else
		res = false;

	for (const auto visit : visited)
		res = res && visit.second;

	return res;
}

graph graph::prim_mst(const char &starting_vertex) const
{
	graph res;
	static auto first_run = true;
	static std::unordered_map<char, int> dist_table;
	static std::unordered_map<char, bool> visited;
	if (first_run) {
		for (const auto vertex : vertices) {
			visited.insert(std::make_pair(vertex, false));
			dist_table[vertex] = operator()(starting_vertex, vertex).weight;
		}
		first_run = false;
	}

	auto adjacent_edges = adjacent(starting_vertex);
	for (const auto current_edge : adjacent_edges)
	{
		auto current_vertex = current_edge.first;
		const auto current_wt = dist_table[starting_vertex] + current_edge.second.weight;
		if (!visited[current_vertex] || dist_table[current_vertex] > current_wt)
		{
			dist_table[current_vertex] = current_wt;
			res(current_edge.second.vertex1, current_edge.second.vertex2) = current_edge.second.weight;
		}
		prim_mst(current_vertex);
	}
	visited[starting_vertex] = true;

	return res;
}