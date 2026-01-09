#include <SDL.h>
#undef main
#include "drawFunctions.h"

using namespace std;

int main() {

	initWindow(1920, 1080, SDL_WINDOW_FULLSCREEN_DESKTOP, 4.0);
	//defines colors (r,g,b, alpha)
	SDL_Color halfBlue = { 0, 0, 128, 255 }; //todo: make color table and brightness manip functions
	SDL_Color halfRed = { 128, 0, 0, 255 }; //todo: make color table and brightness manip functions

	vector<SDL_Point> line1 = { {500, 500}, {700, 700} };

	vector<SDL_Point> line2 = { {500, 500}, {900, 200} };

	struct {

		SDL_Point center = { 400, 450 };

		const int ptCt = 4;

		vector<SDL_Point> localPts = { {0, -25}, {-25, 50}, {0, 25}, {25, 50} };
		vector<SDL_Point> worldPts;

		const int indiceCt = 8;
		vector<int> indices = { 0, 1, 1, 2, 2, 3, 3, 0 };
	} ship;

	struct {

		SDL_Point center = { 800, 400 };

		const int ptCt = 16;

		vector<SDL_Point> localPts = { 
			{0, 0}, {0, 25}, /*nose*/
			{-50, 50}, {50, 50}, /*mouth*/
			{-50,-10}, {-50,-20}, /*pupil 1*/
			{50,-10}, {50,-20}, /*pupil 2*/ 
			{-50, -10}, {-70, -15}, {-50,-20}, {-30,-15}, /*eyelid 1*/
			{50, -10}, {70, -15}, {50,-20}, {30,-15} /*eyelid 2*/ };
		vector<SDL_Point> worldPts;

		const int indiceCt = 24;
		vector<int> indices = { 0, 1, /*nose*/
							2, 3, /*mouth*/
							4, 5, /*pupil 1*/
							6, 7, /*pupil 2*/
							8, 9, 9, 10, 10, 11, 11, 8, /*eyelid 1*/
							12, 13, 13, 14, 14, 15, 15, 12 /*eyelid 2*/};
	} face;

	drawVec(line1[0], line1[1], halfBlue);
	drawVec(line2[0], line2[1], halfBlue); //eventually all draw commands will be obfuscated from the game logic

	renderFrame();
	SDL_Delay(2000);

	transformPoints(ship.localPts, ship.worldPts, ship.ptCt, ship.center, 1.0, 0.0);

	drawVectorPic(ship.worldPts, ship.indices, ship.indiceCt, halfBlue);

	renderFrame();
	SDL_Delay(2000);

	clearScreen(); //make screen black

	transformPoints(ship.localPts, ship.worldPts, ship.ptCt, ship.center, 2.0, 3.1415/4.0);

	drawVectorPic(ship.worldPts, ship.indices, ship.indiceCt, halfBlue);

	transformPoints(face.localPts, face.worldPts, face.ptCt, face.center, 1.0, 0.0);

	drawVectorPic(face.worldPts, face.indices, face.indiceCt, halfRed);

	renderFrame();
	SDL_Delay(2000);

	killRender();

	return EXIT_SUCCESS;
}