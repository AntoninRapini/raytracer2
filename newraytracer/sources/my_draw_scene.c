/*
** my_draw_scene.c for raytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Feb 20 14:13:34 2017 Antonin Rapini
** Last update Wed Mar  8 17:01:42 2017 Antonin Rapini
*/

#include "my_framebuffer.h"
#include "sources.h"
#include "utils.h"
#include <stdio.h>

void my_draw_scene(t_my_framebuffer *frb, t_scene *scene)
{
  int	i;
  int	j;
  sfVector2i curr_pos;
  sfVector3f curr_dir;

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
