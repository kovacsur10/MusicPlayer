#include <iostream>
#include <string>
#include <filesystem>
#include "Album.h"
#include "Musician.h"
#include "MusicPiece.h"
#include "GraphicsEngine.h"

// lesz kép, a fájl neve, de az album neve is, elõadó neve

// albumot csinálni, könyvtárat létrehozni csak album van, benne 1.mp3 2.mp3 tesztnek, zeneszerzõ1 és ezen belül album, hogy látszódjon, hogy mibõl lesz album, még egy + könyvtár és azon belül egy kép

void directoryExplorer(const std::filesystem::path& path) {

    for (auto const& dir_entry : std::filesystem::directory_iterator{ path })
    {
        if (dir_entry.is_directory()) {
            directoryExplorer(dir_entry.path());
        }
        else if (dir_entry.is_regular_file()) {
            std::cout << dir_entry.path() << '\n';
        }
    }
}

int main() {
    directoryExplorer(std::filesystem::path{ "t:\\programs\\MusicPlayer\\" });
}