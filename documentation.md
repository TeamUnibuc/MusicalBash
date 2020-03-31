# Documentation

## GUI looks

The curent (Beta) looks are [here](https://awwapp.com/b/umkwbgwje/).

## SFML Documentation

* [SFML/Music](https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Music.php) 

## MusicalBash Documentation

The design of the project is based on the design patterns descibed [here](https://refactoring.guru/design-patterns).\
Creational: Builder, Singleton\
Structural: Facade, Flyweight\
Behavioral: Command, State, Observer

----------------

## Core

1. [Application](docs/application.md)
    
    Main class, initiates/closes the app and the high level classes to start the app.

1. [UI](docs/ui.md)

    Class interacting with the user via the `sfml/graphics` engine.

1. [Player](docs/player.md)

    Class taking care of the music player, playlists, etc.

1. [Command](docs/command.md)

    Mainly virtual class, contains the small logic parts of the code that actually does something, like: playing sounds, searching for files, saves records of songs, actions of buttons clicked, etc...

    Folosim __*[Command](https://refactoring.guru/design-patterns/command)*__ __Design Pattern__

1. [Index](docs/index.md)

    Class that:
        
    __holds records__ (data) of albums, playlists 
    
    __saves records__ (data) of music files/albums/playlists to the file system

    Returns to the application the list of albums, playlists, songs, etc...

1. [Logger](docs/logger.md)

    Class that enables logging from everywhere in the source code/
    
    Folosim __*[Singleton](https://refactoring.guru/design-patterns/singleton)*__ __Design Pattern__

-------------

## UI-associated classes

### Should be some kind of aggregator / always on pieces that change their internal state to reflect what the user does

Folosim __*[State](https://refactoring.guru/design-patterns/state)*__ __Design Pattern__ pentru urmatoarele clase Window

1. [UPlayerNavigatorWindow](docs/u_player_navigator.md)

    Class able to display the buttons and the status bar of the music player.

2. [UMainWindow](docs/u_album_navigator.md)

    Class that controls the main view (center) of the app.

3. [USideBarWindow](docs/u_side_bar.md)

    Class displaying the side bar, containing the albums navigator, and the settings buttons (TODO: see how to implement them).

*__Sugestie__*: Nu folositi o lista de stari "externe", adica aplicatia e in starea X
Ci mai degraba, Fiecare clasa isi gestioneaza starile ei, si mai apoi, eventual apeland [comenzi](#Command-associated-classes), (comenzi care sunt triggeruite de butoane, cel mai probabil) fiecare isi schimba state-ul vizual

### Basic UI elements

Little objects that are used freely by the 3 main Windows

0. [UBasicElement](docs/)

    Abstract class, to provide a template for the common UI elements

1. [UButton](docs/u_button.md)

2. [UImage](docs/u_image.md)

3. [UTextBox](docs/u_text_box.md)

4. [UScrollView](docs/u_scroll_view.md)

Folosim __*[Builder](https://refactoring.guru/design-patterns/builder)*__ __Design Pattern__ pentru cateva clase de UI. Cel mai probabil la [UScrollView](docs/u_scroll_view.md).

------------------

## Player-associated classes

1. [PAlbum](docs/p_album.md)

    Class maintaining a list of musics from a list of files.

2. [PPlaylist](docs/p_playlist.md)

    Class that maintains a hand picked list of files.

3. [PMusic](docs/p_music.md)

    Class that holds information about a single music / song.
    The hash (id) of a music is exactly: path/to/file/song_name.ext

    Folosim __*[Flyweight](https://refactoring.guru/design-patterns/flyweight)*__ __Design Pattern__ pentru a optimiza memoria (Clasele PPlaylist, PAlbum, Index o sa foloseasca pointeri catre acest Flyweight)

3. [PMusicPlayer](docs/p_music_player.md)

    Class handeling playing the music from a file.
    (The Previous sound_player class)

    Folosim __*[Facade](https://refactoring.guru/design-patterns/facade)*__ __Design Pattern__, intrucat tratam separat fisierele mp3

1. [PTrack](docs/p_track.md)

    Class that handles the current set of songs played. Do you play asong from an album, a playlist, or from the entire gallery?

    Folosim __*[Observer](https://refactoring.guru/design-patterns/observer)*__ __Design Pattern__ peste comenzi, pentru a afla cum se schimba track-ul

------------

## Command-associated classes

1. [CStartMusic](docs/c_start_music.md)

    Class requesting a music to start playing.

1. [CPauseMusic](docs/c_pause_music.md)

    class requesting a music to pause.

1. [CNextMusic](docs/c_next_music.md)

    class requesting a music to pause.

1. [CPreviousMusic](docs/c_previous_music.md)

    class requesting a music to pause.

1. [CClose](docs/c_exit.md)

    class that handles what happens when the app is exiting

1. [CFileSelect](docs/c_file_select.md)

    class selecting a file from filesistem

1. [CFolderSelect](docs/c_folder_select.md)