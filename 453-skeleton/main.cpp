#include <cmath>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/ext/scalar_constants.hpp>
#include <glm/fwd.hpp>
#include <iostream>
#include <math.h>
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
    
    // Press 'R' to refresh/recompile shader
	virtual void keyCallback(int key, int scancode, int action, int mods) {
		if (key == GLFW_KEY_R && action == GLFW_PRESS) {
			shader.recompile();
		}
	}

    // Press 'R' to refresh/recompile shader
	virtual void keyCallback2(int key, int scancode, int action, int mods) {
		if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS) {
			shader.recompile();
		}
	}

private:
	ShaderProgram& shader;
};

GPU_Geometry drawTriangle(vec3 v1,vec3 v2,vec3 v3,vec3 color){
 	// GEOMETRY
	CPU_Geometry cpuGeom;
	GPU_Geometry gpuGeom;

    cpuGeom.verts.push_back(v1);
    cpuGeom.verts.push_back(v2);
    cpuGeom.verts.push_back(v3);

    // colours (these should be in linear space)
	cpuGeom.cols.push_back(color);
	cpuGeom.cols.push_back(color);
	cpuGeom.cols.push_back(color);

	gpuGeom.setVerts(cpuGeom.verts); // Send vertices to GPU 
	gpuGeom.setCols(cpuGeom.cols); // Send colors to GPU
   
    return gpuGeom;
}

GPU_Geometry sierpinsky(int n){
    double dwn_trns = 0.2;
    
    // vertices
	// Bottom left
    vec3 v1 = vec3(cos(M_PI/2), sin(M_PI/2)-dwn_trns, 0.f);
    
    // Bottom right
    vec3 v2 = vec3(cos((4*M_PI)/3+(M_PI/2)), sin((4*M_PI)/3+(M_PI/2))-dwn_trns, 0.f);
    
    // Top
    vec3 v3 = vec3(cos(((2*M_PI)/3)+(M_PI/2)), sin(((2*M_PI)/3)+(M_PI/2))-dwn_trns, 0.f);

    // Color
    vec3 color = vec3(0.0f,1.0f,0.0f);

    GPU_Geometry gpuGeom = drawTriangle(v1,v2,v3,color);

    return gpuGeom;
}

void kochSnowflake(int n){
} 

void uniformTriangleMassCenter(int n){
}

void dragonCurve(int n){
}

void drawTriangle(vec3 a, vec3 b, vec3 c){

}

void drawLine(vec3 a, vec3 b){
}

int main() {
	Log::debug("Starting main");

	// WINDOW
	glfwInit();
	Window window(800, 800, "CPSC 453"); // can set callbacks at construction if desired

	GLDebug::enable();

	// SHADERS
	ShaderProgram shader("shaders/test.vert", "shaders/test.frag");

	// CALLBACKS
	window.setCallbacks(std::make_shared<MyCallbacks>(shader)); // can also update callbacks to new ones

    GPU_Geometry sierpinksi = sierpinsky(0);

    // RENDER LOOP
	while (!window.shouldClose()) {
		glfwPollEvents(); // Refresh screen

		shader.use();
		sierpinksi.bind(); // Bind gpu geometry to OpenGL for use

		glEnable(GL_FRAMEBUFFER_SRGB); // Enable framebuffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear color and depth buffer
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisable(GL_FRAMEBUFFER_SRGB); // disable sRGB for things like imgui

		window.swapBuffers(); // Swapping the double buffer
	}

	glfwTerminate();
	return 0;
}
