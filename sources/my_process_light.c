/*
** my_process_light.c for raytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1bonus/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Mar 18 17:53:32 2017 Antonin Rapini
** Last update Wed May 24 01:01:12 2017 Antonin Rapini
*/

#include "sources.h"
#include "utils.h"
#include <math.h>
#include <stdio.h>

sfColor		my_addlight(sfColor color, float angle)
{
  sfColor	new;

  new.r = color.r * angle;
  new.g = color.g * angle;
  new.b = color.b * angle;
  new.a = 255;
  return (new);
}

sfColor		my_process_light(t_scene *scene, t_intersect *intsct)
{
  int		i;
  int		j;
  sfVector3f	dir;
  int		currdist;
  sfColor      	color;
  float		cos;
  float		angle;

  color = intsct->obj.color;
  i = 0;
  while (scene->lights[i].brightness)
    {
      //dir = my_add_v3(intsct->pos, scene->lights[i].position, -1);
      dir = my_add_v3(scene->lights[i].position, intsct->pos, -1);
      //printf("light pos : %.2f %.2f %.2f\n", scene->lights[i].position.x, scene->lights[i].position.y, scene->lights[i].position.z);
      //printf("dir : %.2f %.2f %.2f\n", dir.x, dir.y, dir.z);
      cos = get_light_coef(dir, intsct->normal);
      //     printf("cos : %.2f\n", cos);
      angle = acos(cos) * (180 / M_PI);
      if (angle <= 90)
	{
	  j = 0;
	  color = my_addlight(color, cos);
	  while (scene->objects[j].type)
	    {
	      if (j != intsct->obji)
		{
		  currdist = my_getdist(scene->objects, intsct->pos, dir, j);
		  if (currdist >= 0 && currdist <= 1)
		    color = my_addlight(color, 0);
		}
	      j++;
	    }
	}
      else
	color = sfBlack;
      i++;
    }
  return (color);
}
