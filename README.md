# Spotlight (A highlighter for linux)
Spotlight, a Linux cursor highlighter, engages when you scroll down with your mouse and returns to default upon scrolling up.
# Demo
[![Demo Video](https://img.youtube.com/vi/096G4vzwgjE/0.jpg)](https://www.youtube.com/watch?v=096G4vzwgjE)

---
# How does it works??
It reads the mouse input from linux kernel from a file  which is located at '/dev/input/eventX' in this particular folder there are different events for different hardware and when activated it toggles the cursor to Highlighter using gnome command

# What did I learn??
I learned how the hardware like mouse,keyboard,touchpad and so on works together with the software under the hood.I learned to make a custom cursor for my system and set it up. I learned some basics of software development using Raylib a graphic library.

# How to run it locally
Idk about other distro how are their file system but for fedora workstation here is
a way to set it up.
## Note: Please install Raylib if you want to use gui version otherwise you can run in terminal  from cli.c

```bash
    git clone https://github.com/Aashish69-96/Spotlight
    cd Spotlight
    mv ./Assets/Spotlight/  /usr/share/icons/
    bash build.sh main.c
```
