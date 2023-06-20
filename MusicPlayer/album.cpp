#include "Album.h"

void Album::addMusic(const MusicPiece& musicpiece) {
	musicpieces.push_back(musicpiece);
}

std::ostream& operator<<(std::ostream& os, const Album& album) {
	os << album.name;
	return os;
}

size_t Album::size() {
	return musicpieces.size();
}

bool Album::empty() {
	return musicpieces.empty();
}

