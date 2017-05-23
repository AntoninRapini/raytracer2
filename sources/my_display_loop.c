/*
** bootstrap_intro.c for bootstrap_intro in /home/antonin.rapini/GraphicalProgramming/BootstrapIntroduction
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Nov 10 09:28:15 2016 Antonin Rapini
** Last update Tue May 23 18:53:49 2017 Antonin Rapini
*/

#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "my_raytracer.h"
#include "utils.h"
#include "sources.h"

void            my_draw_scene(t_my_framebuffer *frb, t_scene *scene)
{
  int           i;
  int           j;
  sfVector2i    curr_pos;
  sfVector3f    curr_dir;

  i = 0;
  while (i < frb->width)
    {
      j = 0;
      while (j < frb->height)
        {
          curr_pos.x = i;
          curr_pos.y = j;
          curr_dir = calc_dir_vector(300, scene->screen_size, curr_pos);
          my_put_pixel(frb, i, j, my_getcolor(scene, curr_dir));
          j++;
        }
      i++;
    }
}

void my_draw_screen(sfRenderWindow *window, t_screenelem *screen, t_scene *scene)
{
  sfRenderWindow_clear(window, sfBlack);
  my_draw_scene(screen->frb, scene);
  sfTexture_updateFromPixels(screen->texture, screen->frb->pixels,
			     screen->frb->width, screen->frb->height, 0, 0);
  sfRenderWindow_drawSprite(window, screen->sprite, NULL);
  sfRenderWindow_display(window);
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
