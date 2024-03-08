#include "SDL_render.h"
#include "SDL_timer.h"
#include "SDL_video.h"
#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_TITLE "imgc"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

struct App
{
  SDL_Window *window;
  SDL_Renderer *renderer;
};

bool sdl_intializer (struct App *imgc);
void app_cleanup (struct App *imgc);
int
main ()
{

  struct App imgc = {
    .window = NULL,
    .renderer = NULL,
  };
  if (!sdl_intializer (&imgc))
    {
      app_cleanup (&imgc);
      printf ("Bad\n");
      exit (1);
    }
  SDL_RenderClear (imgc.renderer);
  SDL_RenderPresent (imgc.renderer);
  SDL_Delay (5000);
  app_cleanup (&imgc);
  printf ("Good\n");
  return 0;
}
/*kill sdl2*/
void
app_cleanup (struct App *imgc)
{
  SDL_DestroyRenderer (imgc->renderer);
  SDL_DestroyWindow (imgc->window);
  SDL_Quit ();
};
/*Return false if there is an Error
 * and false if it just Works*/
bool
sdl_intializer (struct App *imgc)
{
  /* replace with needed sdl inits*/
  if (SDL_Init (SDL_INIT_EVERYTHING))
    {
      fprintf (stderr, "INIT Error : %s\n", SDL_GetError ());
      return false;
    }
  imgc->window = SDL_CreateWindow (WINDOW_TITLE, SDL_WINDOWPOS_CENTERED,
                                   SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                                   SCREEN_HEIGHT, 0);
  if (!imgc->window)
    {
      fprintf (stderr, "WINDOW Error : %s\n", SDL_GetError ());
      return false;
    }
  imgc->renderer = SDL_CreateRenderer (imgc->window, -1, 0);
  if (!imgc->renderer)
    {
      fprintf (stderr, "RENDERER Error : %s\n", SDL_GetError ());
      return false;
    }
  return true;
}
