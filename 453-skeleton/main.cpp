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
bool endProg = false;

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
            if (key == GLFW_KEY_UP && fractal < 4){
                fractal++;
                cout << "Fractal: " << fractal << endl; 
            }
            // Revert to previous fractal
            if (key == GLFW_KEY_DOWN && fractal > 1){
                fractal--;
                cout << "Fractal: " << fractal << endl; 
            }
            // End code
            if(key == GLFW_KEY_Q || key == GLFW_KEY_ESCAPE){
                endProg = true;
            }
        }
	}

    private:
	ShaderProgram& shader;
};

double degreesToRadians(double x){
    return x * (M_PI/180.0);
}

double radiansToDegrees(double x){
    return x * (180.0/M_PI);
}


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
void sierpinsky(vec3 left, vec3 right, vec3 top, int n, CPU_Geometry &cpuGeom, GPU_Geometry &gpuGeom){
    if(n>0){
        //Split points on triangle to midpoints
        vec3 topLeft = vec3((top.x+left.x)/2,(top.y+left.y)/2,0.0); // between top and left
        vec3 topRight = vec3((top.x+right.x)/2,(top.y+right.y)/2,0.0); // between top and right
        vec3 bottomMiddle = vec3((left.x+right.x)/2,(left.y+right.y)/2,0.0); // between left and right
        
        sierpinsky(topLeft,top,topRight,n-1, cpuGeom, gpuGeom);
        sierpinsky(left,topLeft,bottomMiddle,n-1, cpuGeom, gpuGeom);
        sierpinsky(bottomMiddle,topRight,right,n-1, cpuGeom, gpuGeom);
    }
    else{
        drawTriangle(left,right,top,vec3(randomColor(),randomColor(),randomColor()), cpuGeom, gpuGeom);
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

// Given a point and length a endpoint will be returned
vec3 endpoint(vec3 a, double length){
    return vec3(a.x*length,a.y*length,0.0);
}

// Given a pivot point and a length will give rotated line endpoint
vec3 rotate(vec3 a, double length, double angle){
    auto degree = degreesToRadians(angle);
    return vec3(
                a.x + length*cos(degree),
                a.y + length*sin(degree),
                0.0
            );
}


double angleBetweenPointsRad(vec3 v1, vec3 v2){
    return atan2(v1.y-v2.y,v1.x-v2.x);
}

double angleBetweenPointsDeg(vec3 v1, vec3 v2){
    return radiansToDegrees(atan2(v1.y-v2.y,v1.x-v2.x));
}

void kochSnowflake(vec3 left,vec3 right,int n,CPU_Geometry &cpuGeom, GPU_Geometry &gpuGeom){
    double length = sqrt(pow(left.x-right.x,2) + pow(left.y-right.y,2));
    double thirdLength = length/3;
    
    vec3 middleLeft = rotate(left,thirdLength,angleBetweenPointsDeg(right,left)); 
    vec3 middle = rotate(middleLeft,thirdLength,angleBetweenPointsDeg(right,left)+60); 
    vec3 middleRight = rotate(right,thirdLength,angleBetweenPointsDeg(left,right)); 
    
    if(n==0){
        drawLine(left,right,vec3(randomColor(),randomColor(),randomColor()),cpuGeom,gpuGeom); // Seg 1
    }
    else{
        if(n>0){
            kochSnowflake(middleLeft, middle, n-1, cpuGeom, gpuGeom);
            kochSnowflake(left, middleLeft, n-1, cpuGeom, gpuGeom);
            kochSnowflake(middle, middleRight, n-1, cpuGeom, gpuGeom);
            kochSnowflake(middleRight, right, n-1, cpuGeom, gpuGeom);
        }
        else{
            drawLine(left,middleLeft,vec3(randomColor(),randomColor(),randomColor()),cpuGeom,gpuGeom); // Seg 1
            drawLine(middleLeft,middle,vec3(randomColor(),randomColor(),randomColor()),cpuGeom,gpuGeom); // Seg 2
            drawLine(middle,middleRight,vec3(randomColor(),randomColor(),randomColor()),cpuGeom,gpuGeom); // Seg 3
            drawLine(middleRight,right,vec3(randomColor(),randomColor(),randomColor()),cpuGeom,gpuGeom); // Seg 4
        }
    }
} 



void dragonCurve(int n){
}


int main() {
	Log::debug("Starting main");
    cout << "\n\n\t----Controls----" << endl;
    cout << "Up arrow to switch to next fractal" << endl;
    cout << "Down arrow to switch to previous fractal" << endl;
    cout << "Left arrow to decrease fractal iterations" << endl;
    cout << "Right arrow to increase fractal iterations\n\n" << endl;
	
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

    CPU_Geometry cpuGeomKoch;
    GPU_Geometry gpuGeomKoch;
    double dwn_trns = 0.2;
    
    // Upwards Triangle
    vec3 bottomLeft = vec3(cos(M_PI/2), sin(M_PI/2)-dwn_trns, 0.f); // Bottom left
    vec3 bottomRight = vec3(cos((4*M_PI)/3+(M_PI/2)), sin((4*M_PI)/3+(M_PI/2))-dwn_trns, 0.f); // Bottom right
    vec3 top = vec3(cos(((2*M_PI)/3)+(M_PI/2)), sin(((2*M_PI)/3)+(M_PI/2))-dwn_trns, 0.f); // Top
    
    // Upwards Triangle
    vec3 bottomLeftCen = vec3(cos(M_PI/2), sin(M_PI/2), 0.f); // Bottom left
    vec3 bottomRightCen = vec3(cos((4*M_PI)/3+(M_PI/2)), sin((4*M_PI)/3+(M_PI/2)), 0.f); // Bottom right
    vec3 topCen = vec3(cos(((2*M_PI)/3)+(M_PI/2)), sin(((2*M_PI)/3)+(M_PI/2)), 0.f); // Top


    int tempN = -1; // Setting the tempN value to something which isn't default
    int tempFractal = -1; // Setting the tempN value to something which isn't default
    
    // RENDER LOOP
	while (!window.shouldClose()) {
        if(endProg) return 0; // Close program if the user presses Q or Escape        

		glfwPollEvents(); // Refresh screen

		glEnable(GL_FRAMEBUFFER_SRGB); // Enable framebuffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear color and depth buffer  
        
        if(fractal == 1){ // Sierpinsky
            
            cpuGeomUMT.cols.clear();
            cpuGeomUMT.verts.clear();
            
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
        
        if(fractal == 2){ // Uniform Triangle Mass Center
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
            cpuGeomUMT.cols.clear();
            cpuGeomUMT.verts.clear();

            cpuGeomSier.cols.clear();
            cpuGeomSier.verts.clear();
            
            if(n != tempN || fractal != tempFractal){ // Don't render unless something changed
                cout << "Koch Snowflake" << endl;
                shader.use();
                gpuGeomKoch.bind(); // Bind gpu geometry to OpenGL for use

                // Clear the cpu geometry (all the colors and vertices)
                cpuGeomKoch.verts.clear();
                cpuGeomKoch.cols.clear();
                kochSnowflake(bottomLeftCen,bottomRightCen,n,cpuGeomKoch,gpuGeomKoch); 
                kochSnowflake(bottomRightCen,topCen,n,cpuGeomKoch,gpuGeomKoch); 
                kochSnowflake(topCen,bottomLeftCen,n,cpuGeomKoch,gpuGeomKoch); 
            }
            // Set TempN to n so we know that n didn't change
            tempN=n;
            tempFractal = fractal;
        }

        if(fractal == 4){ // Dragon Curve

            cpuGeomKoch.cols.clear();
            cpuGeomKoch.verts.clear();
            
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
        glDrawArrays(GL_LINES, 0, (int) GLsizei(cpuGeomKoch.verts.size()));
		glDisable(GL_FRAMEBUFFER_SRGB); // disable sRGB for things like imgui
        
        window.swapBuffers(); // Swapping the double buffer
	}

	glfwTerminate();
	return 0;
}
