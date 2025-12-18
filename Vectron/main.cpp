#include <SDL.h>
#undef main
#include "drawFunctions.h"

using namespace std;

int main() {

	initWindow(1920, 1080, 4.0);
	//defines colors (r,g,b, alpha)
	SDL_Color halfBlue = { 0, 0, 128, 255 }; //todo: make color table and brightness manip functions

	SDL_Point line1[2] = { {500, 500}, {700, 700} };

	SDL_Point line2[2] = { {500, 500}, {900, 200} };

	struct {

		SDL_Point center = { 400, 450 };

		const int ptCt = 4;

		SDL_Point localPts[4] = { {0, -25}, {-25, 50}, {0, 25}, {25, 50} };
		SDL_Point worldPts[4];

		const int indiceCt = 8;
		int indices[8] = { 0, 1, 1, 2, 2, 3, 3, 0 };
	} ship;

	drawVec(line1, halfBlue);
	drawVec(line2, halfBlue); //eventually all draw commands will be obfuscated from the game logic

	renderFrame();

	transformPoints(ship.localPts, ship.worldPts, ship.ptCt, ship.center, 1.0, 0.0);

	drawVectorPic(ship.worldPts, ship.indices, ship.indiceCt, halfBlue);

	renderFrame();

	clearScreen(); //make screen black

	transformPoints(ship.localPts, ship.worldPts, ship.ptCt, ship.center, 2.0, 3.1415/4.0);

	drawVectorPic(ship.worldPts, ship.indices, ship.indiceCt, halfBlue);

	renderFrame();

	killRender();

	return EXIT_SUCCESS;
}