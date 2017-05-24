/*
** my_getdist.c for tetris in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1bonus/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Mar 19 01:59:31 2017 Antonin Rapini
** Last update Wed May 24 22:45:37 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "sources.h"
#include "utils.h"

static INTERSECT_FUNC const funcs[] =
  {
    intersect_plane,
    intersect_sphere,
    intersect_cylinder,
    intersect_cone,
    NULL
  };

float		my_get_dist(t_object *obj, sfVector3f eye, sfVector3f dir)
{
  sfVector3f	pos;
  int		i;

  i = 0;
  pos = my_add_v3(eye, obj->position, -1);
  while (funcs[i])
    {
      if (obj->type - 1 == i)
	return (funcs[i](obj, pos, dir));
      i++;
    }
  return (-1);
}
