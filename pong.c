
#include <SDL3/SDL.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_video.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_VIDEO);
  bool quit = false;
  SDL_Window *window =
      SDL_CreateWindow("Pong Game", 800, 600, SDL_WINDOW_RESIZABLE);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

  SDL_FRect rectangle;
  rectangle.y = 100;
  rectangle.x = 100;
  rectangle.w = 100;
  rectangle.h = 100;

  while (!quit) {
    SDL_Event ev;
    while (SDL_PollEvent(&ev) != 0) {
      switch (ev.type) {
      case SDL_EVENT_QUIT:
        quit = true;
        break;
      }
    }
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    if (SDL_RenderFillRect(renderer, &rectangle)) {
      printf("showing rectangle\n");
    }

    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
