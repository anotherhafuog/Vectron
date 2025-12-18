#ifndef DRAWFUNCTIONS_H
#define DRAWFUNCTIONS_H
#include <SDL.h>
#include <cmath>
#include <iostream>

using namespace std;
	
void initWindow(int, int, float); //initializes the window to a size int x and int y with a line thickness initialized
void drawVec(SDL_Point[], SDL_Color); //draws a rectangle from two points to emulate a vector line being drawn
void drawVectorPic(SDL_Point[], int[], int, SDL_Color); //draw an object from an array of points and use array of indices to see which points to connect
void transformPoints(const SDL_Point[], SDL_Point*, int, SDL_Point, float, float);
void renderFrame(); //renders current draw commands
void clearScreen(); //wipes window to black
void killRender(); //kills renderer

#endif