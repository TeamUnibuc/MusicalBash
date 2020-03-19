# MusicalBash

## CLI

The project is build with a CLI (Command Line Interface), but we intent to make some nice ASCII art (Eventually with SFML) we could make a nice GUI but it seems overkill. The base class for the CLI is in [inc/sprite.hpp](inc/sprite.hpp).

## Installation

The project relies on the SFML library and mpg123 for encoding mp3 files.
You can install both with the commands:
```
sudo apt install libsfml-dev

sudo apt install libmpg123-dev
```

## SFML

SFML is a graphics / sound / networking engine.
We are mainly using SFML/Sound library. The basic implementation of it is in [inc/sound_player.hpp](inc/sound_player.hpp).

Get SFML from [Here](https://www.sfml-dev.org/tutorials/2.5/start-linux.php).

## Documentation

We have a complete documentation (or so we hope) [here](documentation.md).
