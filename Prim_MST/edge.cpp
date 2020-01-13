#pragma once
#include "edge.h"


edge::edge(const edge& e)
{
	this->vertex1 = e.vertex1;
	this->vertex2 = e.vertex2;
	this->weight = e.weight;
}

edge& edge::operator=(const edge& e)
{
	this->vertex1 = e.vertex1;
	this->vertex2 = e.vertex2;
	this->weight = e.weight;
	return *this;
}

edge& edge::operator=(const int& w)
{
	this->weight = w;
	return *this;
}

bool edge::operator==(const edge& e) const
{
	const auto res = this->weight == e.weight;
	return res;
}

bool edge::operator<(const edge& e) const
{
	return this->weight < e.weight;
}

bool edge::operator>(const edge& e) const
{
	return this->weight > e.weight;
}

bool edge::is_connected() const { return !(weight == INT_MAX); }