#pragma once
#include <string>

enum class Extension {
	WAV,
	MP3,
	OGG,
	FLAC
};

Extension toExtension(const std::string& ext);