#include "drawFunctions.h"

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

float thickness;


void initWindow(int windowSizeX, int windowSizeY, float userThickness) {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(windowSizeX, windowSizeY, 0, &window, &renderer);
	SDL_RenderSetScale(renderer, 1, 1); //initialize window
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_ADD); // sets colors to additive blend
	thickness = userThickness;
}

void drawVec(SDL_Point pts[], SDL_Color color) {
	float x0 = pts[0].x;
	float x1 = pts[1].x;

	float y0 = pts[0].y;
	float y1 = pts[1].y;// define points from struct

	float dx = x1 - x0;
	float dy = y1 - y0;
	float length = sqrt((dx * dx) + (dy * dy)); //find length of vector

	float ptx = (-dy / length) * (thickness / 2.0f);
	float pty = (dx / length) * (thickness / 2.0f); //calculate offsets from origin points for rect

	struct SDL_Vertex verts[4];
	verts[0].position = { x0 + ptx, y0 + pty };
	verts[1].position = { x1 + ptx, y1 + pty };
	verts[2].position = { x1 - ptx, y1 - pty };
	verts[3].position = { x0 - ptx, y0 - pty }; // Compute points for rect

	for (int i = 0; i < 4; ++i) {
		verts[i].color = color;
	} //set color

	const int indices[6] = { 0, 1, 2, 2, 3, 0 };

	SDL_RenderGeometry(renderer, nullptr, verts, 4, indices, 6); //draw
}

void drawVectorPic(SDL_Point verts[], int indices[], int indiceCt, SDL_Color color) {
	for (int i = 0; i < indiceCt - 1; i += 2) {
		SDL_Point pts[2] = {verts[indices[i]],verts[indices[i+1]]};
		drawVec(pts, color);
	} //read two indices, get the points from verts and draw a line between
}

void transformPoints(const SDL_Point localPts[], SDL_Point* worldPts, int ptCt, SDL_Point center, float scale, float angle) {
	float cs = cosf(angle);
	float sn = sinf(angle);

	for (int i = 0; i < ptCt; i++) {
		float x = localPts[i].x * scale;
		float y = localPts[i].y * scale;

		worldPts[i].x = (int)(x * cs - y * sn + center.x);
		worldPts[i].y = (int)(x * sn + y * cs + center.y);
	}
}

void printChar(unsigned char theChar, SDL_Point pt, SDL_Color color, float scale) {

}

void printString(string theString, SDL_Point pt, SDL_Color color, float scale) {

}

void renderFrame() {
	SDL_RenderPresent(renderer);
	SDL_Delay(3000); //better time function will come soon
}

void clearScreen() {
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND); // sets colors to blend
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer); // screen wipe
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_ADD); // resets to additive blend
}

void killRender() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();//deallocate and close
}