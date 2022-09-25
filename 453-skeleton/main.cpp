#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/fwd.hpp>
#include <iostream>
#include "Geometry.h"
#include "GLDebug.h"
#include "Log.h"
#include "ShaderProgram.h"
#include "Window.h"

using namespace std;
using namespace glm;

// Callbacks are for keyboard controls
class MyCallbacks : public CallbackInterface {

public:
	MyCallbacks(ShaderProgram& shader) : shader(shader) {}
    
	virtual void keyCallback(int key, int scancode, int action, int mods) {
		if (key == GLFW_KEY_R && action == GLFW_PRESS) {
			shader.recompile();
		}
	}

private:
	ShaderProgram& shader;
};

void sierpinski(int n){
    
}

void drawTriangle(vec3 a, vec3 b, vec3 c){

}

int main() {
	Log::debug("Starting main");

	// WINDOW
	glfwInit();
	Window window(800, 800, "Assignment 1 - Harkamal Randhawa"); // can set callbacks at construction if desired

	GLDebug::enable();

	// SHADERS
	ShaderProgram shader("shaders/test.vert", "shaders/test.frag");

	// CALLBACKS
	window.setCallbacks(std::make_shared<MyCallbacks>(shader)); // can also update callbacks to new ones

	// GEOMETRY
	CPU_Geometry cpuGeom;
	GPU_Geometry gpuGeom;

	// vertices
	cpuGeom.verts.push_back(vec3(-0.5f, -0.5f, 0.f));
	cpuGeom.verts.push_back(vec3(0.5f, -0.5f, 0.f));
	cpuGeom.verts.push_back(vec3(0.f, 0.5f, 0.f));
	
    // colours (these should be in linear space)
	cpuGeom.cols.push_back(vec3(1.f, 0.f, 0.f));
	cpuGeom.cols.push_back(vec3(0.f, 1.f, 0.f));
	cpuGeom.cols.push_back(vec3(0.f, 0.f, 1.f));

	gpuGeom.setVerts(cpuGeom.verts); // Send vertices to GPU 
	gpuGeom.setCols(cpuGeom.cols); // Send colors to GPU

	// RENDER LOOP
	while (!window.shouldClose()) {
		glfwPollEvents(); // Refresh screen

		shader.use();
		gpuGeom.bind(); // Bind gpu geometry to OpenGL for use

		glEnable(GL_FRAMEBUFFER_SRGB); // Enable framebuffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear color and depth buffer
		glDrawArrays(GL_LINE_LOOP, 0, 3);
		glDisable(GL_FRAMEBUFFER_SRGB); // disable sRGB for things like imgui

		window.swapBuffers(); // Swapping the double buffer
	}

	glfwTerminate();
	return 0;
}
