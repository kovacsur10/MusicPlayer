#include <iostream>
#include <string>
#include <filesystem>
#include "Album.h"
#include "Musician.h"
#include "MusicPiece.h"
#include "GraphicsEngine.h"

// lesz k�p, a f�jl neve, de az album neve is, el�ad� neve

// albumot csin�lni, k�nyvt�rat l�trehozni csak album van, benne 1.mp3 2.mp3 tesztnek, zeneszerz�1 �s ezen bel�l album, hogy l�tsz�djon, hogy mib�l lesz album, m�g egy + k�nyvt�r �s azon bel�l egy k�p

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