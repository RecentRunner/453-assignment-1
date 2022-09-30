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
int fractal = 1;

// Callbacks are for keyboard controls
class MyCallbacks : public CallbackInterface {
    public:
	MyCallbacks(ShaderProgram& shader) : shader(shader) {}
    
    
	virtual void keyCallback(int key, int scancode, int action, int mods) {
	    if (action == GLFW_PRESS || action == GLFW_REPEAT){
            // Press 'R' to refresh/recompile shaders
            if(key == GLFW_KEY_R){
                cout << "Recompile" << endl;
                shader.recompile();
            }
            // Decrement n
            if (key == GLFW_KEY_LEFT && n > 0) {
                n--;
			    cout << "Left n: " << n << endl;
		    }
            // Increment n
       	    if (key == GLFW_KEY_RIGHT) {
                n++;
			    cout << "Right n: " << n << endl;
		    }
            // Switch to next fractal
            if (key == GLFW_KEY_UP){
                fractal++;
                cout << "Fractal: " << fractal << endl; 
            }
            // Revert to previous fractal
            if (key == GLFW_KEY_DOWN && fractal > 1){
                fractal--;
                cout << "Fractal: " << fractal << endl; 
            }
        }
	}

    private:
	ShaderProgram& shader;
};

double randomColor(){
    return (double)(rand()) / ((double)(RAND_MAX));
}

// Draw the triangle given 3 positions and color
void drawTriangle(vec3 bottomLeft,vec3 bottomRight,vec3 top,vec3 color, CPU_Geometry &cpuGeom, GPU_Geometry &gpuGeom){

    // push the vertices back into their vector
    cpuGeom.verts.push_back(bottomLeft);
    cpuGeom.verts.push_back(bottomRight);
    cpuGeom.verts.push_back(top);

    // colours (these should be in linear space)
	cpuGeom.cols.push_back(color);
	cpuGeom.cols.push_back(color);
	cpuGeom.cols.push_back(color);

	gpuGeom.setVerts(cpuGeom.verts); // Send vertices to GPU 
	gpuGeom.setCols(cpuGeom.cols); // Send colors to GPU
}

// Draw sierpinsky given the number of recursions also returns number of vertices
void sierpinsky(vec3 a, vec3 c, vec3 b, int n, CPU_Geometry &cpuGeom, GPU_Geometry &gpuGeom){
    if(n>0){
        //Split points on triangle to midpoints
        vec3 d = vec3((b.x+a.x)/2,(b.y+a.y)/2,0.0); // between top and left
        vec3 e = vec3((b.x+c.x)/2,(b.y+c.y)/2,0.0); // between top and right
        vec3 f = vec3((a.x+c.x)/2,(a.y+c.y)/2,0.0); // between left and right
        
        sierpinsky(d,b,e,n-1, cpuGeom, gpuGeom);
        sierpinsky(a,d,f,n-1, cpuGeom, gpuGeom);
        sierpinsky(f,e,c,n-1, cpuGeom, gpuGeom);
    }
    else{
        drawTriangle(a,c,b,vec3(randomColor(),randomColor(),randomColor()), cpuGeom, gpuGeom);
    } 
}

void drawLine(vec3 a, vec3 b, vec3 color, CPU_Geometry &cpuGeom, GPU_Geometry &gpuGeom){
 
    // push the vertices back into their vector
    cpuGeom.verts.push_back(a);
    cpuGeom.verts.push_back(b);

    // colours (these should be in linear space)
	cpuGeom.cols.push_back(color);
	cpuGeom.cols.push_back(color);

	gpuGeom.setVerts(cpuGeom.verts); // Send vertices to GPU 
	gpuGeom.setCols(cpuGeom.cols); // Send colors to GPU 
}

void uniformTriangleMassCenter(vec3 left, vec3 right, vec3 top, int n, CPU_Geometry &cpuGeom, GPU_Geometry &gpuGeom){
    //Split points on triangle to midpoints
    vec3 center = vec3((top.x+left.x+right.x)/3,(top.y+left.y+right.y)/3,0.0); // between top and left
    
    if(n>0){
        uniformTriangleMassCenter(left,top,center,n-1, cpuGeom, gpuGeom);
        uniformTriangleMassCenter(left,center,right,n-1, cpuGeom, gpuGeom);
        uniformTriangleMassCenter(center,top,right,n-1, cpuGeom, gpuGeom);
    }
    else{
        drawLine(left,right,vec3(randomColor(),randomColor(),randomColor()), cpuGeom, gpuGeom);
        drawLine(left,top,vec3(randomColor(),randomColor(),randomColor()), cpuGeom, gpuGeom);
        drawLine(top,right,vec3(randomColor(),randomColor(),randomColor()), cpuGeom, gpuGeom);
        drawLine(left,center,vec3(randomColor(),randomColor(),randomColor()), cpuGeom, gpuGeom);
        drawLine(top,center,vec3(randomColor(),randomColor(),randomColor()), cpuGeom, gpuGeom);
        drawLine(right,center,vec3(randomColor(),randomColor(),randomColor()), cpuGeom, gpuGeom);
    } 
}

void kochSnowflake(int n){
} 

void dragonCurve(int n){
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
    
    CPU_Geometry cpuGeomSier;
    GPU_Geometry gpuGeomSier;

    CPU_Geometry cpuGeomUMT;
    GPU_Geometry gpuGeomUMT;

    double dwn_trns = 0.2;
    
    // Sierpinsky's Triangle
    vec3 bottomLeft = vec3(cos(M_PI/2), sin(M_PI/2)-dwn_trns, 0.f); // Bottom left
    vec3 bottomRight = vec3(cos((4*M_PI)/3+(M_PI/2)), sin((4*M_PI)/3+(M_PI/2))-dwn_trns, 0.f); // Bottom right
    vec3 top = vec3(cos(((2*M_PI)/3)+(M_PI/2)), sin(((2*M_PI)/3)+(M_PI/2))-dwn_trns, 0.f); // Top


    int tempN = -1; // Setting the tempN value to something which isn't default
    int tempFractal = -1; // Setting the tempN value to something which isn't default
    
    // RENDER LOOP
	while (!window.shouldClose()) {
		glfwPollEvents(); // Refresh screen

		glEnable(GL_FRAMEBUFFER_SRGB); // Enable framebuffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear color and depth buffer  
        
        if(fractal == 1){ // Sierpinsky
            if(n != tempN || fractal != tempFractal){ // Don't render unless something changed
                cout << "Sierpinsky's Triangle" << endl;
                shader.use();
                gpuGeomSier.bind(); // Bind gpu geometry to OpenGL for use

                // Clear the cpu geometry (all the colors and vertices)
                cpuGeomSier.verts.clear();
                cpuGeomSier.cols.clear();
                sierpinsky(bottomLeft,bottomRight,top,n,cpuGeomSier,gpuGeomSier); 
            }
            // Set TempN to n so we know that n didn't change
            tempN=n;
            tempFractal = fractal;
        }
        
        if(n != tempN || fractal != tempFractal){ // Uniform Triangle Mass Center
            cpuGeomSier.cols.clear();
            cpuGeomSier.verts.clear();

            if(n != tempN || fractal != tempFractal){ // Don't render unless something changed
                cout << "Uniform Triangle Mass Center" << endl;
                shader.use();
                gpuGeomUMT.bind(); // Bind gpu geometry to OpenGL for use

                // Clear the cpu geometry (all the colors and vertices)
                cpuGeomUMT.verts.clear();
                cpuGeomUMT.cols.clear();
                uniformTriangleMassCenter(bottomLeft,bottomRight,top,n,cpuGeomUMT,gpuGeomUMT); 
            }
            // Set TempN to n so we know that n didn't change
            tempN=n;
            tempFractal = fractal;
        }

        if(fractal == 3){ // Koch Snowflake
            cpuGeomSier.cols.clear();
            cpuGeomSier.verts.clear();


            if(n != tempN || fractal != tempFractal){ // Don't render unless something changed
                cout << "Koch Snowflake" << endl;
            }
            // Set TempN to n so we know that n didn't change
            tempN=n;
            tempFractal = fractal;
        }

        if(fractal == 4){ // Dragon Curve
            cpuGeomSier.cols.clear();
            cpuGeomSier.verts.clear();


            if(n != tempN || fractal != tempFractal){ // Don't render unless something changed
                cout << "Dragon Curve" << endl;
            }
            // Set TempN to n so we know that n didn't change
            tempN=n;
            tempFractal = fractal;
        }

        glDrawArrays(GL_LINES, 0, (int) GLsizei(cpuGeomUMT.verts.size()));
        glDrawArrays(GL_TRIANGLES, 0, (int) GLsizei(cpuGeomSier.verts.size()));
		glDisable(GL_FRAMEBUFFER_SRGB); // disable sRGB for things like imgui
        
        window.swapBuffers(); // Swapping the double buffer
	}

	glfwTerminate();
	return 0;
}
