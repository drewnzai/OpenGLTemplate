#include "glad.h"
#include <GLFW/glfw3.h>

#include <iostream>

void viewportResize(GLFWwindow* window, int width, int height);

//Triangle Coordinates
const float vertices[] = {
	0.0f, 0.5f, 0.0f,
	0.5f, 0.0f, 0.0f,
	-0.5f, 0.0f, 0.0f
};

const char* vertexShaderSource =
"#version 330 core\n"
"layout(location = 0) in vec3 position;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(position.x, position.y, position.z, 1.0f);\n"
"}\0";

const char* fragmentShaderSource =
"#version 330 core\n"
"out vec4 outputColor;\n"
"void main()\n"
"{\n"
"outputColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\0";


int main() {
	
	//Initialising GLFW components
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Create a window
	GLFWwindow* window = glfwCreateWindow(600, 700, "Triangle Template", NULL, NULL);

	glfwMakeContextCurrent(window);

	//Resizes the viewport whenever the user or OS resizes the window
	glfwSetFramebufferSizeCallback(window, viewportResize);

	//Loads all OpenGL functions and associated pointers
	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

	unsigned int vertexShader, fragmentShader, shaderProgram;

	//Create the vertex shader
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	//create the fragment shader
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	//Create the shader program, attach the shaders to it, and enable the execution of the program
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	//Deletes the shaders as they're no longer necessary
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	unsigned int VBO, VAO;
	
	//Create the vertex buffer object and vertex array object
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	//Binds the VAO
	glBindVertexArray(VAO);

	//Binds the VBO to a preconfigured buffer and populates it with the triangle coordinates data
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	//Render the window and triangle
	while(!glfwWindowShouldClose(window)){
	
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO); 
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	//De-allocates the unneeded resources
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);

	//De-allocate all GLFW resources
	glfwTerminate();
	
	return 0;

}

void viewportResize(GLFWwindow* window, int width, int height){
	
	glViewport(0, 0, width, height);

}