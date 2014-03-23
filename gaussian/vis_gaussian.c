#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define WIN_HT 640
#define WIN_WD 480

int main(int argc, char **argv) {
	int i;
	int j;
	int quit_flag = 0; 
	int draw_flag = 1; 
	SDL_Window *win;
	SDL_Renderer *ren;
	SDL_Rect background;
	SDL_Point points[100]; 
	SDL_Event response;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
		return 1;
	}

	win = SDL_CreateWindow("Gaussian dist visualization", 100, 100, WIN_HT, WIN_WD, SDL_WINDOW_SHOWN); 
	
	if (win == NULL) {
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		return 1;
	}

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); 

	/*Create the background*/
	background.x = 0; 
	background.y = 0;
	background.h = WIN_HT;
	background.w = WIN_WD;

	/*Set draw color to white*/
	SDL_SetRenderDrawColor(ren, 255, 255, 255, 255); 
	
	/*Start the rendering*/
	SDL_RenderClear(ren);
	SDL_RenderFillRect(ren, &background);

	/*Set Render color for points to black*/
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255); 

	srand(time(NULL));
	/*Start putting the points on the screen*/
#if 0
	for (i = 0; i < MAX_POINTS/100; i++) {
		for (j = 0; j < 100; j++) { 
			points[j].x = rand() % WIN_HT;
			points[j].y = rand() % WIN_WD;
		}
		SDL_RenderDrawPoints(ren, points, 100);
		SDL_RenderPresent(ren); 

	}
#endif
	while(!quit_flag) {
		SDL_PollEvent(&response); 
		if (draw_flag) {
			for (j = 0; j < 100; j++) { 
				points[j].x = rand() % WIN_HT;
				points[j].y = rand() % WIN_WD;
			}
		}
		SDL_RenderDrawPoints(ren, points, 100);
		SDL_RenderPresent(ren); 
		if (response.type == SDL_MOUSEBUTTONDOWN) draw_flag = 0; 
		if (response.type == SDL_QUIT) quit_flag = 1; 
	}

/*	SDL_Delay(4000);*/
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);

	SDL_Quit();
	return 0;
}








