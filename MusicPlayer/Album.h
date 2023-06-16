#pragma once
#include <vector>
#include <string>
#include <filesystem>
#include "MusicPiece.h"
#include <iostream>


class Album {
public:
	Album(const std::string& name, const std::filesystem::path& path) : name(name), path(path) {}
	Album(const std::string& name, const std::filesystem::path& path, const std::vector<MusicPiece>& musicpieces) : name(name), path(path), musicpieces(musicpieces) {}
	~Album(){}

	void addMusic( const MusicPiece& musicpiece);

	friend std::ostream& operator<<(std::ostream& os, const Album& album);

private:
	std::string             name;
	std::filesystem::path   path;
	std::vector<MusicPiece> musicpieces;
};