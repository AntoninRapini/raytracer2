/*
** bootstrap_intro.c for bootstrap_intro in /home/antonin.rapini/GraphicalProgramming/BootstrapIntroduction
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Nov 10 09:28:15 2016 Antonin Rapini
** Last update Tue Mar 14 22:56:15 2017 Antonin Rapini
*/

#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics/RenderWindow.h>
#include <math.h>
#include "my_screenelement.h"
#include "utils.h"
#include "sources.h"

void		display_loop(sfRenderWindow *window, t_screenelem *screen, t_scene *scene)
{

  /* my_draw_scene(screen->frb, scene);
     sfTexture_updateFromPixels(screen->texture, screen->frb->pixels,
     screen->frb->width, screen->frb->height, 0, 0);*/
  while (sfRenderWindow_isOpen(window))
    {
      sfRenderWindow_clear(window, sfBlack);
      sfRenderWindow_drawSprite(window, screen->sprite, NULL);
      sfRenderWindow_display(window);
      my_get_transformations(scene);
      my_draw_scene(screen->frb, scene);
      sfTexture_updateFromPixels(screen->texture, screen->frb->pixels,
				 screen->frb->width, screen->frb->height, 0, 0);
    }
}

int			my_display(int width, int height)
{
  t_screenelem		*screen;
  sfRenderWindow	*window;
  t_scene		*scene;

  if ((window = create_window("SFML Window", width, height)) == NULL)
    return (1);
  if ((scene = my_create_scene(width, height)) == NULL)
    return (1);
  screen = my_create_screenelem(width, height);
  display_loop(window, screen, scene);
  sfRenderWindow_destroy(window);
  return (0);
}
