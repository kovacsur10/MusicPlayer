#include <iostream>
#include <string>
#include <filesystem>
#include "GraphicsEngine.h"

// lesz kép, a fájl neve, de az album neve is, elõadó neve,


enum class Extension {
	WAV,
	MP3,
	OGG,
	FLAC
};

class MusicPiece {
public:

private:
	std::string           name;
	Extension             extension;
	std::filesystem::path path;
};


class Album {
public:

private:
	std::string             name;
	std::filesystem::path   path;
	std::vector<MusicPiece> musicpieces;
};



class Musician {
public:

private:
	std::string name;
};


int main() {

}