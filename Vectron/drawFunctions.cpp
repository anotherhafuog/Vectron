#include "drawFunctions.h"

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

float thickness = 4.0;



void initWindow(int windowSizeX, int windowSizeY) {
	cout << "In init\n";
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(windowSizeX, windowSizeY, 0, &window, &renderer);
	SDL_RenderSetScale(renderer, 1, 1); //initialize window

	//SDL_SetRenderDrawColor(renderer, 0, 0, 128, 255); //set color to blue
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_ADD); // sets colors to additive blend
}

void drawVec(SDL_Point pts[], SDL_Color color) {
	cout << "In draw\n";
	float x0 = pts[0].x;
	float x1 = pts[1].x;

	float y0 = pts[0].y;
	float y1 = pts[1].y;// define points from struct

	float dx = x1 - x0;
	float dy = y1 - y0;
	float length = sqrt((dx * dx) + (dy * dy));

	float ptx = (-dy / length) * (thickness / 2.0f);
	float pty = (dx / length) * (thickness / 2.0f);

	struct SDL_Vertex verts[4];
	verts[0].position = { x0 + ptx, y0 + pty };
	verts[1].position = { x1 + ptx, y1 + pty };
	verts[2].position = { x1 - ptx, y1 - pty };
	verts[3].position = { x0 - ptx, y0 - pty }; // Compute points for rect

	for (int i = 0; i < 4; ++i) {
		verts[i].color = color;
	} //set color

	const int indices[6] = { 0, 1, 2, 2, 3, 0 };

	SDL_SetRenderDrawColor(renderer, 0, 0, 128, 255); //set color to blue for now

	SDL_RenderGeometry(renderer, nullptr, verts, 4, indices, 6); //draw
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
	cout << "In destroy\n";
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();//deallocate and close
}