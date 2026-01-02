#ifndef DRAWFUNCTIONS_H
#define DRAWFUNCTIONS_H
#include <SDL.h>
#include <cmath>
#include <iostream>

using namespace std;
	
void initWindow(int, int, float); 
//initializes the window to a size int x and int y with a line thickness initialized
void drawVec(SDL_Point[], SDL_Color); 
//draws a rectangle from two points to emulate a vector line being drawn
void drawVectorPic(SDL_Point[], int[], int, SDL_Color); 
//draw an object from an array of points and use array of indices to see which points to connect
void transformPoints(const SDL_Point[], SDL_Point*, int, SDL_Point, float, float); 
//takes an array of points local to centerpoint, point array in the world to be written to, # of pts, centerpt, scale and angle, and transforms the points to be ready for drawing
void printChar(unsigned char, SDL_Point, SDL_Color, float);
//takes character, point on the screen, color, and scale, and draws a letter on the screen
void printString(string, SDL_Point, SDL_Color, float);
//takes string, point on the screen, color, and scale, and draws the string on the screen
void renderFrame(); //renders current draw commands
void clearScreen(); //wipes window to black
void killRender(); //kills renderer

#endif