#pragma once
#include <climits>

class edge
{
public:
	edge(char v1, char v2, int wt = INT_MAX) : vertex1(v1), vertex2(v2), weight(wt) {}

	edge(const edge& e)
	{
		this->vertex1 = e.vertex1;
		this->vertex2 = e.vertex2;
		this->weight = e.weight;
	}

	edge& operator=(const edge& e)
	{
		this->vertex1 = e.vertex1;
		this->vertex2 = e.vertex2;
		this->weight = e.weight;
		return *this;
	}

	edge& operator=(const int& w)
	{
		this->weight = w;
		return *this;
	}

	bool operator==(const edge& e) const
	{
		const auto res =
			(this->vertex1 == e.vertex1)
			&& (this->vertex2 == e.vertex2)
			&& (this->weight == e.weight);
		return res;
	}

	bool is_connected() const { return !(weight == INT_MAX); }

	char	vertex1;
	char	vertex2;
	int	weight;
};
