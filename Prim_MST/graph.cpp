#include "graph.h"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>

void graph::print_table(bool sort_vertices)
{
	const auto n = vertices.size();
	if (n == 0) {
		std::cout << "\n" << static_cast<unsigned char>(LUCNR);
		std::cout << "     ";
		std::cout << static_cast<unsigned char>(RUCNR);
		std::cout << "\n" << static_cast<unsigned char>(VRT);
		std::cout << "Empty";
		std::cout << static_cast<unsigned char>(VRT) << "\n";
		std::cout << static_cast<unsigned char>(LLCNR);
		std::cout << "     ";
		std::cout << static_cast<unsigned char>(RLCNR);
	}
	else {
		if (sort_vertices)
			std::sort(vertices.begin(), vertices.end());

		size_t w1 = 0;
		for (const auto i : vertices) {
			for (const auto j : vertices) {
				size_t l;
				std::ostringstream tmpstream;
				auto this_edge = this->operator()(i, j);
				if (!this_edge.is_connected())
					tmpstream << std::right << std::noshowpos << INF << " ";
				else
					tmpstream << std::right << std::noshowpos << this_edge.weight << " ";
				l = tmpstream.str().length();
				w1 = (w1 > l ? w1 : l);
			}
		}
		const auto w2 = ((w1 + 1)*n);

		std::cout << "\n" << " " << " " << static_cast<unsigned char>(VRT);
		for (auto k = 0; k < n; ++k) {
			std::cout << std::right << std::setfill(' ') << std::setw(w1) << vertices[k] << " ";
		}
		std::cout << "\n" << static_cast<unsigned char>(HOR) << static_cast<unsigned char>(HOR)
			<< static_cast<unsigned char>(CEN);
		for (auto k = 0; k < w2; ++k) {
			std::cout << static_cast<unsigned char>(HOR);
		}

		for (const auto i : vertices) {
			std::cout << "\n";
			for (const auto j : vertices) {
				if (j == *vertices.begin()) {
					std::cout << " " << i << static_cast<unsigned char>(VRT);
				}
				auto this_edge = this->operator()(i, j);
				if (!this_edge.is_connected())
					std::cout << std::right << std::setfill(' ') << std::setw(w1) << INF << " ";
				else
					std::cout << std::right << std::setfill(' ')
					<< std::setw(w1) << this_edge.weight << " ";
			}
		}
	}
}
