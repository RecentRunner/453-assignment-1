#include <cmath>
#include <cstdlib>
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
#include <random>

using namespace std;
using namespace glm;

int n = 0;

// Callbacks are for keyboard controls
class MyCallbacks : public CallbackInterface {

	MyCallbacks(ShaderProgram& shader) : shader(shader) {}
    
    // Press 'R' to refresh/recompile shader
	virtual void keyCallback(int key, int scancode, int action, int mods) {
		if (key == GLFW_KEY_LEFT && action == GLFW_PRESS) {
			cout << "LEFT" << endl;
            n--;
            shader.recompile();
		}
       	if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS) {
			cout << "RIGHT" << endl;
            n++;
            shader.recompile();
		}
	}

	ShaderProgram& shader;
};

double randomColor(){
    return (double)(rand()) / ((double)(RAND_MAX));
}

// Draw the triangle given 3 positions and color
int drawTriangle(vec3 bottomLeft,vec3 bottomRight,vec3 top,vec3 color, CPU_Geometry &cpuGeom, GPU_Geometry &gpuGeom){

    cpuGeom.verts.push_back(bottomLeft);
    cpuGeom.verts.push_back(bottomRight);
    cpuGeom.verts.push_back(top);

    // colours (these should be in linear space)
	cpuGeom.cols.push_back(color);
	cpuGeom.cols.push_back(color);
	cpuGeom.cols.push_back(color);

	gpuGeom.setVerts(cpuGeom.verts); // Send vertices to GPU 
	gpuGeom.setCols(cpuGeom.cols); // Send colors to GPU
    return 3; 
}

// Draw sierpinsky given the number of recursions also returns number of vertices
int sierpinsky(vec3 a, vec3 c, vec3 b, int n, CPU_Geometry &cpuGeom, GPU_Geometry &gpuGeom){
    int drawNum = 0;

    if(n>0){
        //Split points on triangle to midpoints
        vec3 d = vec3((b.x+a.x)/2,(b.y+a.y)/2,0.0); // between top and left
        vec3 e = vec3((b.x+c.x)/2,(b.y+c.y)/2,0.0); // between top and right
        vec3 f = vec3((a.x+c.x)/2,(a.y+c.y)/2,0.0); // between left and right
        
        drawNum += sierpinsky(d,b,e,n-1, cpuGeom, gpuGeom);
        drawNum += sierpinsky(a,d,f,n-1, cpuGeom, gpuGeom);
        drawNum += sierpinsky(f,e,c,n-1, cpuGeom, gpuGeom);
    }
    else{
        drawNum += drawTriangle(a,c,b,vec3(randomColor(),randomColor(),randomColor()), cpuGeom, gpuGeom);
    }
    return drawNum;
}

void kochSnowflake(int n){
} 

void uniformTriangleMassCenter(int n){
}

void dragonCurve(int n){
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
    
    CPU_Geometry cpuGeom;
    GPU_Geometry gpuGeom;   

    // Sierpinsky's Triangle
    double dwn_trns = 0.2;
    vec3 bottomLeft = vec3(cos(M_PI/2), sin(M_PI/2)-dwn_trns, 0.f); // Bottom left
    vec3 bottomRight = vec3(cos((4*M_PI)/3+(M_PI/2)), sin((4*M_PI)/3+(M_PI/2))-dwn_trns, 0.f); // Bottom right
    vec3 top = vec3(cos(((2*M_PI)/3)+(M_PI/2)), sin(((2*M_PI)/3)+(M_PI/2))-dwn_trns, 0.f); // Top


    int drawNum = 0;

        
    // RENDER LOOP
	while (!window.shouldClose()) {
		glfwPollEvents(); // Refresh screen

		shader.use();
		gpuGeom.bind(); // Bind gpu geometry to OpenGL for use

		glEnable(GL_FRAMEBUFFER_SRGB); // Enable framebuffer
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear color and depth buffer  
        
		drawNum += sierpinsky(bottomLeft,bottomRight,top,n,cpuGeom,gpuGeom);
        glDrawArrays(GL_TRIANGLES, 0, drawNum);
		glDisable(GL_FRAMEBUFFER_SRGB); // disable sRGB for things like imgui
        
        window.swapBuffers(); // Swapping the double buffer
	}

	glfwTerminate();
	return 0;
}
