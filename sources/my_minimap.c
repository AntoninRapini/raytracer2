/*
** my_minimap.c for raytracer in /home/raphael.goulmot/rendu/raytracer2
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Sun May 28 19:18:57 2017 Raphaël Goulmot
** Last update Sun May 28 20:22:36 2017 Raphaël Goulmot
*/

#include "sources.h"
#include "utils.h"

static void	draw_square(t_scene *scene, sfVector2i pos
			    , int size, sfColor color)
{
  int		x;
  int		y;

  y = pos.y;
  while (y++ < pos.y + size)
    {
      x = pos.x;
      while (x < pos.x + size)
	{
	  my_put_pixel(scene->screen->frb, x, y - 1, color);
	  x++;
	}
    }
}

void		display_minimap(t_scene *scene)
{
  sfVector2i	pos;
  int		o;

  pos.x = scene->screen->frb->width - 90;
  pos.y = 0;
  draw_square(scene, pos, 90, sfBlack);
  o = -1;
  while (scene->objects[++o].type)
    {
      if (scene->objects[o].type > 1
	  && scene->objects[o].position.x >= scene->eye_pos.x - 225
	  && scene->objects[o].position.x <= scene->eye_pos.x + 225
	  && scene->objects[o].position.y >= scene->eye_pos.y - 225
	  && scene->objects[o].position.y <= scene->eye_pos.y + 225)
	{
	  pos.y = 90 -
	    (scene->objects[o].position.x - (scene->eye_pos.x - 200)) / 5 - 10;
	  pos.x = scene->screen->frb->width -
	    (scene->objects[o].position.y - (scene->eye_pos.y - 200)) / 5 - 10;
	  draw_square(scene, pos, 10, sfGreen);
	}
    }
  pos.x = scene->screen->frb->width - 50;
  pos.y = 40;
  draw_square(scene, pos, 10, sfWhite);
}
