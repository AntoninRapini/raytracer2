/*
** bootstrap_intro.c for bootstrap_intro in /home/antonin.rapini/GraphicalProgramming/BootstrapIntroduction
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Nov 10 09:28:15 2016 Antonin Rapini
** Last update Tue May 23 10:48:58 2017 HartWoom
*/

#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "my_raytracer.h"
#include "utils.h"
#include "sources.h"

void my_draw_screen(sfRenderWindow *window, t_screenelem *screen, t_scene *scene)
{
  sfRenderWindow_clear(window, sfBlack);
  sfRenderWindow_drawSprite(window, screen->sprite, NULL);
  sfRenderWindow_display(window);
  my_draw_scene(screen->frb, scene);
  sfTexture_updateFromPixels(screen->texture, screen->frb->pixels,
			     screen->frb->width, screen->frb->height, 0, 0);
}

void		my_display_loop
(sfRenderWindow *window, t_screenelem *screen, t_scene *scene)
{
  sfEvent	event;
  my_draw_screen(window, screen, scene);
  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
	    sfRenderWindow_close(window);
	  if (event.type == sfEvtClosed)
	    sfRenderWindow_close(window);
	  if (event.type == sfEvtKeyPressed)
	    {
	      my_get_transformations(scene);
	      my_draw_screen(window, screen, scene);
	    }
	}
    }
}
