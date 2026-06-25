#pragma once

#include <algorithm>
#include <vector>

namespace nonstd {
	template <typename Comparable>
	void sort(std::vector<Comparable>& comparables) {
		// TODO: replace std::sort with my own algorithm;
		std::sort(comparables.begin(), comparables.end());
	}
}