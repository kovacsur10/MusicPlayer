#include <iostream>
#include <string>
#include <filesystem>
#include "Album.h"
#include "Musician.h"
#include "MusicPiece.h"
#include "GraphicsEngine.h"
#include "types.h"

#include "GraphicsEngine.h"
#include "Image.h"
#include "Button.h"

using namespace SDLEngine;
using namespace std::literals::string_literals;

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



    GraphicsEngine& engine = GraphicsEngine::GetInstance();
    engine.CreateWindow("almafa"s, 800, 500, 0);
    //engine.LoadFont("arial"s, "c:\\DEVS\\0001CODING\\C++projekt\\images\\arial.ttf"s);
    engine.LoadFont("arial"s, "resources\\fonts\\arial.ttf"s);

    ReturnCode returncode = engine.LoadImage("futyi"s, "resources\\images\\futyifeles.jpg"s);

    auto& registry = engine.GetRegistry();
    auto id = registry.Create<Image>(Dimension(194, 260), "futyi"s);

    auto image = dynamic_cast<Image*>(registry.Get(id));
    image->Move(Point(200, 200));

    engine.AddItemToDraw(id);

    auto buttonId = registry.Create<Button>(ButtonType::Type::PRIMARY, Dimension(50, 40), "start"s);
    auto button = dynamic_cast<Button*>(registry.Get(buttonId));
    button->bind("start"s, BoundableTypes::STRING, "Start"s);

    DrawableCallbackFunctions startCallback([&button](const Point& buttonClicked) { button->Hide(); });
    button->AddCallback(Events::LEFT_MOUSE_BUTTON_DOWN, startCallback);
    button->Move(Point(20, 20));

    engine.AddItemToDraw(buttonId);

    engine.Start();
}

// a polcra akkor kerülhet fel, ha van benne zeneszám, ha nincs akkor ne