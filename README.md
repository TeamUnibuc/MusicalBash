# MusicalBash

## SFML

SFML is a graphics / sound / networking engine.
We are mainly using SFML/Sound library. The basic implementation of it is in [inc/sound_player.hpp](inc/sound_player.hpp).

Get SFML from [Here](https://www.sfml-dev.org/tutorials/2.5/start-linux.php).

## CLI

The project is build with a CLI (Command Line Interface), but we intent to make some nice ASCII art (Eventually with SFML) we could make a nice GUI but it seems overkill. The base class for the CLI is in [inc/sprite.hpp](inc/sprite.hpp).

## Status

Sound is working fine on my distro (Ubuntu 20.04 x64 Gnome), while using builtin gnome-terminal, however it seems it does not work neither on windows WSL nor on the VSCode terminal.

Sound is working fine on Ubuntu 18.04 x64 Gnome, while using builtin gnome-terminal and on the VSCode terminal.

