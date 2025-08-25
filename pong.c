#include <SDL3/SDL.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_video.h>
#include <stdio.h>

#define HEIGHT 800
#define WIDTH 600
#define RECT_HEIGHT 100
#define RECT_WIDTH 15

int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_VIDEO);
  bool quit = false;
  SDL_Window *window =
      SDL_CreateWindow("Pong Game", HEIGHT, WIDTH, SDL_WINDOW_RESIZABLE);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

  SDL_FRect ply1 = (SDL_FRect){100, 100, RECT_WIDTH, RECT_HEIGHT};
  SDL_FRect ply2 = (SDL_FRect){700, 100, RECT_WIDTH, RECT_HEIGHT};
  SDL_FRect seperator = (SDL_FRect){400, 0, 10, HEIGHT};

  while (!quit) {
    SDL_Event ev;
    while (SDL_PollEvent(&ev) != 0) {
      switch (ev.type) {
      case SDL_EVENT_QUIT:
        quit = true;
        break;
      }
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    if (SDL_RenderFillRect(renderer, &ply1)) {
      printf("showing rectangle 1\n");
    }
    if (SDL_RenderFillRect(renderer, &ply2)) {
      printf("showing rectangle 2\n");
    }
    if (SDL_RenderFillRect(renderer, &seperator)) {
      printf("showing seperator\n");
    }

    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
