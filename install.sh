#!/bin/bash

# a complete list of depedencies can be found at
# https://github.com/TeamUnibuc/MusicalBash/blob/master/README.md


# needs to be run as root
if [ "$EUID" -ne 0 ]
  then echo "Please run as root"
  exit
fi


# used for the sfml binaries
apt -y install libsfml-dev

# used for computing the mp3 music length
apt -y install libmpg123-dev
apt -y install mp3info

# used for basically all external commands
apt -y install zenity

# used for downloading music from the web
apt -y install youtube-dl

# used for sorting the index into the database
apt -y install libsqlite3-dev

# remove .musicalbash folder
rm -rf $HOME/.musicalbash