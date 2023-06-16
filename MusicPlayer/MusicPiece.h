#pragma once
#include <string>
#include <filesystem>

enum class Extension {
	WAV,
	MP3,
	OGG,
	FLAC
};

class MusicPiece {
public:
	MusicPiece(std::string name, Extension extension, std::filesystem::path path) : name(name), extension(extension), path(path) {}
	~MusicPiece(){}
	// getterek
	// meg a ki tudja még milyen lófasz :D

private:
	std::string           name;
	Extension             extension;
	std::filesystem::path path;
};
