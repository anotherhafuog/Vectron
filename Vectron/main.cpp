#include <SDL.h>
#undef main
#include "drawFunctions.h"

using namespace std;

int main() {

	initWindow(1920, 1080);
	//defines colors (r,g,b, alpha)
	SDL_Color halfBlue = { 0, 0, 128, 255 }; //todo: make color table and brightness manip functions

	SDL_Point line1[2] = { {500, 500}, {700, 700} };

	SDL_Point line2[2] = { {500, 500}, {900, 200} };

	SDL_Point shipPts[4] = { {900, 900}, {850, 1000}, {900, 975}, {950, 1000}};

	const int shipIndiceCt = 8;
	int shipIndices[shipIndiceCt] = { 0, 1, 1, 2, 2, 3, 3, 0 };

	drawVec(line1, halfBlue);
	drawVec(line2, halfBlue); //eventually all draw commands will be obfuscated

	renderFrame();

	drawVectorPic(shipPts, shipIndices, shipIndiceCt, halfBlue, 1);

	renderFrame();

	clearScreen(); //make screen black

	renderFrame();

	killRender();

	return EXIT_SUCCESS;
}