#pragma once
#include <climits>

class edge
{
public:
	edge(char v1, char v2, int wt = INT_MAX) : vertex1(v1), vertex2(v2), weight(wt) {}

	edge(const edge& e);
	edge& operator=(const edge& e);
	edge& operator=(const int& w);
	bool operator==(const edge& e) const;
	bool operator<(const edge& e) const;
	bool operator>(const edge& e) const;
	bool is_connected() const;

	char	vertex1;
	char	vertex2;
	int		weight;
};
