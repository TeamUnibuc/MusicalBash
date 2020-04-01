# Documentation

## GUI looks

The curent (Beta) looks are [here](https://awwapp.com/b/umkwbgwje/).

-------------

## SFML Documentation

* [SFML/Music](https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Music.php) 

-------------

## MusicalBash Documentation

The design of the project is based on the design patterns descibed [here](https://refactoring.guru/design-patterns).\
Creational: Builder, Singleton\
Structural: Facade, Flyweight\
Behavioral: Command, State, Observer

-------------

## Core

1. [Application](docs/application.hpp)
    
    Main class, initiates/closes the app and the high level classes to start the app.

1. [UI](docs/ui.hpp)

    Class interacting with the user via the `sfml/graphics` engine.

1. [Player](docs/player.hpp)

    Class taking care of the music player, playlists, etc.

1. [Command](docs/command.hpp)

    Mainly virtual class, contains the small logic parts of the code that actually does something, like: playing sounds, searching for files, saves records of songs, actions of buttons clicked, etc...

    Folosim __*[Command](https://refactoring.guru/design-patterns/command)*__ __Design Pattern__

1. [PIndex](inc/player/p_index.hpp)

    Class that:
        
    __holds records__ (data) of albums, playlists 
    
    __saves records__ (data) of music files/albums/playlists to the file system

    Returns to the application the list of albums, playlists, songs, etc...

1. [Logger](docs/logger.hpp)

    Class that enables logging from everywhere in the source code/
    
    Folosim __*[Singleton](https://refactoring.guru/design-patterns/singleton)*__ __Design Pattern__

-------------

## UI-associated classes

### Should be some kind of aggregator / always on pieces that change their internal state to reflect what the user does

Folosim __*[State](https://refactoring.guru/design-patterns/state)*__ __Design Pattern__ pentru urmatoarele clase Window

1. [UPlayerNavigatorWindow](docs/ui/u_player_navigator.hpp)

    Class able to display the buttons and the status bar of the music player.

2. [UMainWindow](docs/ui/u_album_navigator.hpp)

    Class that controls the main view (center) of the app.

3. [USideBarWindow](docs/ui/u_side_bar.hpp)

    Class displaying the side bar, containing the albums navigator, and the settings buttons (TODO: see how to implement them).

*__Sugestie__*: Nu folositi o lista de stari "externe", adica aplicatia e in starea X
Ci mai degraba, Fiecare clasa isi gestioneaza starile ei, si mai apoi, eventual apeland [comenzi](#Command-associated-classes), (comenzi care sunt triggeruite de butoane, cel mai probabil) fiecare isi schimba state-ul vizual

### Basic UI elements

Little objects that are used freely by the 3 main Windows

0. [UBasicElement](docs/)

    Abstract class, to provide a template for the common UI elements

1. [UButton](docs/ui/u_button.hpp)

2. [UImage](docs/ui/u_image.hpp)

3. [UTextBox](docs/ui/u_text_box.hpp)

4. [UScrollView](docs/ui/u_scroll_view.hpp)

Folosim __*[Builder](https://refactoring.guru/design-patterns/builder)*__ __Design Pattern__ pentru cateva clase de UI. Cel mai probabil la [UScrollView](docs/ui/u_scroll_view.hpp).

------------------

## Player-associated classes

As Palbum, PPlaylist and PTrack are basically doing the exact same thing, I created Track and the two others shoud inherit from it without changing anything (or almost).

1. [PTrack](inc/player/p_track.hpp)

    Class that handles the current set of songs played. Do you play asong from an album, a playlist, or from the entire gallery?

    Folosim __*[Observer](https://refactoring.guru/design-patterns/observer)*__ __Design Pattern__ peste comenzi, pentru a afla cum se schimba track-ul

1. [PAlbum](inc/player/p_album.hpp)

    Class maintaining a list of musics from a list of files.

2. [PPlaylist](inc/player/p_playlist.hpp)

    Class that maintains a hand picked list of files.

3. ~~[PMusic](inc/player/p_music.hpp)~~

    ~~Class that holds information about a single music / song.
    The hash (id) of a music is exactly: path/to/file/song_name.ext~~
    __NOT needed, as we only have to remember the path, which is stored by default in all albums / tracks__ 

    Folosim __*[Flyweight](https://refactoring.guru/design-patterns/flyweight)*__ __Design Pattern__ pentru a optimiza memoria (Clasele PPlaylist, PAlbum, Index o sa foloseasca pointeri catre acest Flyweight)

3. [PMusicPlayer](inc/player/p_music_player.hpp)

    Class handeling playing the music from a file.
    (The Previous sound_player class)

    Folosim __*[Facade](https://refactoring.guru/design-patterns/facade)*__ __Design Pattern__, intrucat tratam separat fisierele mp3

------------

## Command-associated classes

1. [CStartMusic](inc/command/c_start_music.hpp)

    Class requesting a music to start playing.

1. [CPauseMusic](inc/command/c_pause_music.hpp)

    class requesting a music to pause.

1. [CNextMusic](inc/command/c_next_music.hpp)

    class requesting a music to pause.

1. [CPreviousMusic](inc/command/c_previous_music.hpp)

    class requesting a music to pause.

1. [CClose](inc/command/c_exit.hpp)

    class that handles what happens when the app is exiting

1. [CFileSelect](inc/command/c_file_select.hpp)

    class selecting a file from filesistem

1. [CFolderSelect](inc/command/c_folder_select.hpp)