/*
** bootstrap_intro.c for bootstrap_intro in /home/antonin.rapini/GraphicalProgramming/BootstrapIntroduction
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Nov 10 09:28:15 2016 Antonin Rapini
** Last update Wed May 24 18:53:42 2017 Raphaël Goulmot
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

void my_draw_screen(sfRenderWindow *window, t_screenelem *screen
		    , t_scene *scene)
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
  bool		lock;

  lock = false;
  scene->window = window;
  scene->screen = screen;
  while (scene->running && sfRenderWindow_isOpen(window))
    {
      if (scene->refresh && !lock)
	{
	  lock = true;
	  my_draw_screen(scene->window, scene->screen, scene);
	  lock = false;
	  scene->refresh = 0;
	}
    }
  launch_thread(scene);
  if (sfRenderWindow_isOpen(window))
    sfRenderWindow_close(window);
}
