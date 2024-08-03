# Spotlight (A highlighter for linux)
Spotlight, a Linux cursor highlighter, toggles when you press 's' on your keyboard.
# Demo
Click to play demo:
[![Demo Video](https://img.youtube.com/vi/-qTh3gop9tg/0.jpg)](https://www.youtube.com/watch?v=-qTh3gop9tg)
---
# User-Interface
![ON](https://github.com/Aashish69-96/Spotlight/blob/main/Assets/images/spotlighon.png)
![OFF](https://github.com/Aashish69-96/Spotlight/blob/main/Assets/images/spotlightoff.png)
---
# How does it works??
It reads the keyboard input from linux kernel from a file  which is located at '/dev/input/eventX' in this particular folder there are different events for different hardware and when activated it toggles the cursor to Highlighter using gnome command

# What did I learn??
I learned how the hardware like mouse,keyboard,touchpad and so on works together with the software under the hood.I learned to make a custom cursor for my system and set it up. I learned some basics of software development using Raylib a graphic library.About multithreading in c using pthreads.

# How to run it locally
For gnome  here is a way to set it up as filesystem are same for linux env.
---
Note: Please install Raylib(optional) if you want to use gui version otherwise you can run in terminal  from cli.c if it says permission required then permission must be given to read the input file done by 'sudo chown:'usename' eventX' eventX is a variable to be find go to /dev/input connect keyboard once and disconnect carefully observe which file is vanishing as disconnected and respawn connecting and change the program for that particular file in preprosser of program.Also in bash file change the username from 'aashish' to your username and event file too.

```bash
    git clone https://github.com/Aashish69-96/Spotlight
    cd Spotlight
    sudo cp -R ./Assets/Spotlight/  /usr/share/icons/
    cd src
    bash build.sh
```
# License
Copyright(c) 2024 Aashish Adhikari
This software is distributed under MIT license

