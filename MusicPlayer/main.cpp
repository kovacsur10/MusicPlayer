#include <iostream>
#include <string>
#include <filesystem>
#include "Album.h"
#include "Musician.h"
#include "MusicPiece.h"
#include "GraphicsEngine.h"
#include "types.h"

// lesz k�p, a f�jl neve, de az album neve is, el�ad� neve
std::vector<Album> albums;

void directoryExplorer(const std::filesystem::path& path) {
    Album album(path.filename().string(), path);
    
    for (auto const& dir_entry : std::filesystem::directory_iterator{ path })
    {
        if (dir_entry.is_directory()) {
            directoryExplorer(dir_entry.path());
        }
        else if (dir_entry.is_regular_file()) {
            MusicPiece musicpiece(dir_entry.path().filename().string(), toExtension(dir_entry.path().extension().string()), dir_entry.path());
            album.addMusic(musicpiece);
        }
    }
    albums.push_back(album);
}

// ha albumon bel�l van m�g egy album akkor az k�l�n album
// mappa neve �s b�rmilyen f�jlok azok a zenesz�mok

int main() {
    directoryExplorer(std::filesystem::path{ "t:\\teszt" }); //ezzel itt mi a her�t lehet? o.o TODO

    for (const auto& album : albums) {
        std::cout << album << std::endl;
    }
}