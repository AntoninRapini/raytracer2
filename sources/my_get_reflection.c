/*
** my_get_reflection.c for raytracer in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer2/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat May 27 23:39:34 2017 Antonin Rapini
** Last update Sun May 28 05:27:01 2017 Antonin Rapini
*/

#include "sources.h"
#include <stdio.h>

sfColor		my_get_reflection(t_intersect *intsct, sfVector3f reflection_v, t_scene *scene)
{
  int		i;
  sfColor       background;
  t_intersect	new_intsct;
  float		dist;

  background.r = 120;
  background.g = 140;
  background.b = 170;
  background.a = 255;
  new_intsct.dir = reflection_v;
  new_intsct.origin = intsct->pos;
  new_intsct.dist = -1;
  dist = -1;
  i = 0;
  while (scene->objects[i].type)
    {
      if (intsct->obji != i)
	{
	  dist = my_get_dist(scene->objects + i, intsct->pos, reflection_v);
	  if (dist > 0 && (dist < new_intsct.dist || new_intsct.dist < 0))
	    {
	      new_intsct.dist = dist;
	      new_intsct.obj = scene->objects[i];
	      new_intsct.obji = i;
	    }
	}
      i++;
    }
  if (new_intsct.dist != -1)
    {
      new_intsct.pos.x = intsct->pos.x + reflection_v.x * new_intsct.dist;
      new_intsct.pos.y = intsct->pos.y + reflection_v.y * new_intsct.dist;
      new_intsct.pos.z = intsct->pos.z + reflection_v.z * new_intsct.dist;
      new_intsct.normal = my_get_normal(&(new_intsct.obj), new_intsct.pos);
      return (my_process_light(scene, &new_intsct));
    }
  return (background);
}
