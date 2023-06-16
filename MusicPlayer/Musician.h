#pragma once
#include <string>


class Musician {
public:
	Musician(std::string name) : name(name) {}
	~Musician(){}

private:
	std::string name;
};
