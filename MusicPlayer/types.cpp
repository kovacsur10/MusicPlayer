#include "types.h"
#include "utils.h"

Extension toExtension(const std::string& ext) {
	if (tolower(ext) == "wav") {
		return Extension::WAV;
	}
	else if (tolower(ext) == "mp3") {
		return Extension::MP3;
	}
	else if (tolower(ext) == "ogg") {
		return Extension::OGG;
	}
	else if (tolower(ext) == "flac") {
		return Extension::FLAC;
	}
}