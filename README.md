# Step 01

The first milestone in creating the [Dinodeck](http://dinodeck.com/) engine.
A project that can open a widow and setup an OpenGL context on both Windows and Mac.
This project uses SDL and OpenGL.

This a minimal, instructional project showing how to start make a game engine. The Dinodeck engine itself started with this as it's first milestone.

## Building for Windows

![Step 01 running on windows](windows.png)

I downloaded mingw, navigated to /etc and renamed fstab.sample to fstab. Then downloaded a 32bit version of sdl. Ran make on the root of the SDL code, checked the examples by entering /tests and running ./configure, make. Then it should be possible to build.

## Building on Mac

![Step 01 running on mac](mac.png)

## Building on Android

This requires quite a lot of setup.