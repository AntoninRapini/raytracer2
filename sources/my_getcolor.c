/*
** my_draw_objects.c for raytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Mar  7 19:27:50 2017 Antonin Rapini
** Last update Thu May 25 21:19:09 2017 Antonin Rapini
*/

#include <SFML/Graphics.h>
#include "sources.h"
#include "utils.h"
#include <stdio.h>

void	my_get_intersect
(t_object *objs, sfVector3f eye, sfVector3f dir, t_intersect *intsct)
{
  int	i;
  float	currdist;

  currdist = -1;
  intsct->dir = dir;
  intsct->origin = eye;
  intsct->dist = -1;
  i = 0;
  while (objs[i].type)
    {
      currdist = my_get_dist(objs + i, eye, dir);
      if (currdist > 0 && (currdist < intsct->dist || intsct->dist < 0))
	{
	  intsct->dist = currdist;
	  intsct->obj = objs[i];
	  intsct->obji = i;
	}
      i++;
    }
  if (intsct->dist != -1)
    {
      intsct->pos.x = eye.x + dir.x * intsct->dist;
      intsct->pos.y = eye.y + dir.y * intsct->dist;
      intsct->pos.z = eye.z + dir.z * intsct->dist;
      intsct->normal = my_get_normal(&(intsct->obj), intsct->pos);
    }
}

sfColor		my_getcolor(t_scene *scene, sfVector3f dir)
{
  t_intersect	intersect;

  my_get_intersect(scene->objects, scene->eye_pos, dir, &intersect);
  if (intersect.dist != -1)
    return (my_process_light(scene, &intersect));
  return (sfBlack);
}
