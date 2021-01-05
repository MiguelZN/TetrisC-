#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600

int main(int argc, char* argv[]){
    SDL_Window *window;                    // Declare a pointer
    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    //Create the SDL window
    window = SDL_CreateWindow(
        "TetrisC++",         
        SDL_WINDOWPOS_UNDEFINED,          
        SDL_WINDOWPOS_UNDEFINED,          
        SCREEN_WIDTH,                             
        SCREEN_HEIGHT,                               
        SDL_WINDOW_OPENGL                 
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if(!renderer) {
        fprintf(stderr, "Could not create renderer\n");
        return 1;
    }

    if(TTF_Init()==-1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }  

    TTF_Font *font = TTF_OpenFont("/usr/local/texlive/2018/texmf-dist/fonts/truetype/public/dejavu/DejaVuSans.ttf", 16);
    if(!font) {
        fprintf(stderr, "Couldn't load font\n");
        return 1;
    }

    SDL_Color color;
    color.r = 255;
    color.g = 255;
    color.b = 255;
    color.a = 255;
    SDL_Surface *text = TTF_RenderUTF8_Blended(font, "Hello world", color);

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, text);
    SDL_FreeSurface(text);
    text = NULL;
    SDL_Rect dest;
    dest.x = 200;
    dest.y = 200;
    dest.w = 100;
    dest.h = 75;

    //SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(renderer, texture, NULL, &dest);


    // A basic main loop to prevent blocking
    bool is_running = true;
    SDL_Event event;

    while (is_running) {
        while (SDL_PollEvent(&event)) {
        

            if (event.type == SDL_QUIT) {
                printf("Quitting..\n");
                is_running = false;
            }

            if(event.type == SDL_KEYDOWN){
                printf("Pressing\n");
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    SDL_DestroyTexture(texture);
    texture = NULL;
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}