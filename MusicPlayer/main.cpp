#include <iostream>
#include <string>
#include <filesystem>
#include "Album.h"
#include "Musician.h"
#include "MusicPiece.h"
#include "GraphicsEngine.h"
#include "types.h"

// lesz kép, a fájl neve, de az album neve is, elõadó neve
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

// ha albumon belül van még egy album akkor az külön album
// mappa neve és bármilyen fájlok azok a zeneszámok

int main() {
    directoryExplorer(std::filesystem::path{ "t:\\teszt" }); //ezzel itt mi a herét lehet? o.o TODO

    for (const auto& album : albums) {
        std::cout << album << std::endl;
    }
}