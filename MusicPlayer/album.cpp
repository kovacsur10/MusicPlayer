#include "Album.h"

void Album::addMusic(const MusicPiece& musicpiece) {
	musicpieces.push_back(musicpiece);
}

std::ostream& operator<<(std::ostream& os, const Album& album) {
	os << album.name;
	return os;
}