#include <SDL.h>
#undef main
#include "drawFunctions.h"

using namespace std;

int main() {

	initWindow(1920, 1080);
	//defines colors (r,g,b, alpha)
	SDL_Color atariBlue = { 0, 0, 128, 255 }; //todo: make color table

	SDL_Point line1[2] = { {500, 500}, {700, 700} };

	SDL_Point line2[2] = { {500, 500}, {900, 200} };

	drawVec(line1, atariBlue);
	drawVec(line2, atariBlue); //eventually all draw commands will be obfuscated

	renderFrame();

	clearScreen(); //make screen black

	renderFrame();

	killRender();

	return 0;
}