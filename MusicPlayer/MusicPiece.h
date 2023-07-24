#pragma once
#include <string>
#include <filesystem>
#include "types.h"


class MusicPiece {
public:
	MusicPiece(const std::string& name, const Extension& extension, const std::filesystem::path& path) : name(name), extension(extension), path(path) {}
	~MusicPiece(){}
	// getterek
	// meg a ki tudja m�g milyen l�fasz :D


private:
	std::string           name;
	Extension             extension;
	std::filesystem::path path;
};