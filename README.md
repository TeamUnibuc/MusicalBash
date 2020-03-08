# MusicalBash

## The concept

Make a program (let's call it MusicalBash), made of two parts.

The first part is the _'Back End'_, which should be able to:
* Be started / closed by the frontend.
* Play a music given by the frontend. Change volume.
* Search music files in a list of folders (given by the frontend).
* List musics and sort them by a few criterias (so have an index of available music sorted somewhere).

The _'Front End'_ part has to be able to:
* Start / stop the back end service when prompted by user.
* Receive / transmit requestest from the user to the backend or text from the backend to the user.


## How to create self-sustaining backend (with no active terminals)

I propose to make an unix-only software (linux is better anyways).
[This page](https://superuser.com/questions/178587/how-do-i-detach-a-process-from-terminal-entirely) shows how to detach completly a process from the parent terminal. 