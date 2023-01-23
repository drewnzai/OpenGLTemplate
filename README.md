# STARTER TEMPLATE

  

This repository is a template for creating an OpenGL project.

I use [**GLFW**](https://www.glfw.org/) (Graphics Library Framework) and [**GLAD**](https://glad.dav1d.de/) (Multi-language Loader Generator) to create an OpenGL context and load all function pointers, respectively.

Tried it in Windows but found it to involve too many steps, and I just prefer programming in Linux (Kali - 2022.4).

## Installation Process
Basically, just folllow through in this article by [Priyanshu](https://medium.com/geekculture/a-beginners-guide-to-setup-opengl-in-linux-debian-2bfe02ccd1e)

## Run on Linux
With the **glad.c** file in your working directory, run in your terminal

```bash
g++ triangle.cpp glad.c -ldl -glfw -o triangle
`