# Documentation

## SFML Documentation

* [SFML/Music](https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Music.php) 

## MusicalBash Documentation

The design of the project is based on the design pattern descibed [here](https://refactoring.guru/design-patterns/command).

### Core

1. [Application](docs/application.md)
    
    Main class, initiates/closes the app and the high level classes to start the app.

1. [UI](docs/ui.md)

    Class interacting with the user via the `sfml/graphics` engine.

1. [Player](docs/player.md)

    Class taking care of the music player, playlists, etc.

1. [Command](docs/command.md)

    Mainly virtual class, contains the small logic parts of the code that actually does something, like: playing sounds, searching for files, saves records of songs, actions of buttons clicked, etc...

1. [Index](docs/index.md)

    Class that:
        
    __holds records__ (data) of albums, playlists 
    
    __saves records__ (data) of music files/albums/playlists to the file system

    Returns to the application the list of albums, playlists, songs, etc...

## UI-associated classes

### Should be some kind of aggregator / always on pieces that change their internal state to reflect what the user does

*__Sugestie__*: Implementati aceste clase folosind [State Design Pattern](https://refactoring.guru/design-patterns/state)

*__Sugestie__*: Nu folositi o lista de stari "externe", adica aplicatia e in starea X
Ci mai degraba, Fiecare clasa isi gestioneaza starile ei, si mai apoi, eventual apeland [comenzi](https://refactoring.guru/design-patterns/command), (comenzi care sunt triggeruite de butoane, cel mai probabil) fiecare isi schimba state-ul vizual

1. [UPlayerNavigatorWindow](docs/u_player_navigator.md)

    Class able to display the buttons and the status bar of the music player.

2. [UMainWindow](docs/u_album_navigator.md)

    Class that controls the main view (center) of the app.

3. [USideBarWindow](docs/u_side_bar.md)

    Class displaying the side bar, containing the albums navigator, and the settings buttons (TODO: see how to implement them).

### Basic UI elements

### Little objects that are used freely by the 3 main Windows

0. [UBasicElement](docs/)

    Abstract class, to provide a template for the common UI elements

1. [UButton](docs/u_button.md)

2. [UImage](docs/u_image.md)

3. [UTextBox](docs/u_text_box.md)

4. [UScrollView](docs/u_scroll_view.md)

## Player-associated classes

1. [PAlbum](docs/p_album.md)

    Class maintaining a list of musics from a list of files.

2. [PPlaylist](docs/p_playlist.md)

    Class that maintains a hand picked list of files.

3. [PMusicPlayer](docs/p_music_player.md)

    Class handeling playing the music from a file.
    (The Previous sound_player class)

1. [PTrack](docs/p_track.md)

    Class that handles the current set of songs played. Do you play asong from an album, a playlist, or from the entire gallery?

    *__Sugestie__*: Aici folosim [observer](https://refactoring.guru/design-patterns/observer) peste comenzi, pentru a afla cum se schimba track-ul

1.  ~~[PMusicFinder](docs/p_music_finder.md)~~ Obsolete

    ~~Class able to look (ideally asyncroniously) through the documents to find playable files.~~

    Good ideea, but this is more like a subclass of commands.


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
