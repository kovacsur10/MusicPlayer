#pragma once
#include <string>
#include <algorithm>

std::string tolower(const std::string& in) {
	std::string out(in.size(),'\0');
	/*for (auto c : in) {
		out.push_back(std::tolower(c));
	}*/
	std::transform(in.begin(), in.end(), out.begin(), [](unsigned char c) { return std::tolower(c); });
	return out;
}

