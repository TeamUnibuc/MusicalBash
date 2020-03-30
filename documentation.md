# Documentation

## SFML Documentation

* [SFML/Music](https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Music.php) 

## MusicalBash Documentation

The design of the project is based on the design pattern descibed [here](https://refactoring.guru/design-patterns/command).

### Core

1. [Application](docs/application.md)
    
    Main class, creating both the UI and the backend classes.

1. [UI](docs/ui.md)

    Class interacting with the user via the `sfml/graphics` engine.

1. [Player](docs/player.md)

    Class taking care of the music player, playlists, etc.

1. [Command](docs/command.md)

    Mainly virtual class, sending requests / commands from the UI to the player (like for instance `STOP MUSIC` or `GETPLAYLIST`).

## UI-associated classes

1. [UPlayerNavigator](docs/u_player_navigator.md)

    Class able to display the buttons and the status bar of the music player.

1. [UAlbumNavigator](docs/u_album_navigator.md)

    Class displaying the active album in the central part of the app.

1. [USideBar](docs/u_side_bar.md)

    Class displaying the side bar, containing the albums navigator, and the settings buttons (TODO: see how to implement them).

## Player-associated classes

1. [PAlbum](docs/p_album.md)

    Class maintaining a list of musics from a list of files.

1. [PMusicPlayer](docs/p_music_player.md)

    Class handeling playing the music from a file.

1. [PMusicFinder](docs/p_music_finder.md)

    Class able to look (ideally asyncroniously) through the documents to find playable files.

## Command-associated classes

1. [CStartMusic](docs/c_start_music.md)

    Class requesting a music to start playing.

1. [CPauseMusic](docs/c_pause_music.md)

    class requesting a music to pause.

1. [CStopMusic](docs/c_stop_music.md)

    class requesting a music to pause.

1. [CNextMusic](docs/c_next_music.md)

    class requesting a music to pause.

1. [CPreviousMusic](docs/c_previous_music.md)

    class requesting a music to pause.

1. [CGetAlbum](docs/c_get_album.md)

    class requesting a music to pause.