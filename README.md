# STARTER TEMPLATE

  

This repository is a template for creating an OpenGL project.

I use [**GLFW**](https://www.glfw.org/) (Graphics Library Framework) and [**GLAD**](https://glad.dav1d.de/) (Multi-language Loader Generator) to create an OpenGL context and load all function pointers, respectively.

Tried it in Windows but found it to involve too many steps, and I just prefer programming in Linux (Kali - 2022.4).

## Installation Process
Basically, just folllow through in this article by [Priyanshu](https://medium.com/geekculture/a-beginners-guide-to-setup-opengl-in-linux-debian-2bfe02ccd1e)

### Modifications
I decided to create a project that could also run on Linux and possibly OS X, with minimal additional configuration.
As such, I have decided to use CMake to build my project.
This is visible through my use of **CMakeLists.txt** file.

This does not work on Windows, sadly.

## Building
Create a directory called **build** and ``cd `` into it.

In the *build* directory run **cmake** on the CMakeLists.txt file in the source path:
```bash
cmake ../CMakeLists.txt
```

## Running
To run the application, move to the **build** directory and run **Make**
```bash
make
```

Then run the created executable
```bash
./triangle
```
