
#include <SDL3/SDL.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_video.h>

int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_CreateWindow("Pong Game", 600, 600, SDL_WINDOW_RESIZABLE);
  SDL_Delay(6000);
}
