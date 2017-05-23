/*
** my_getdist.c for tetris in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1bonus/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Mar 19 01:59:31 2017 Antonin Rapini
** Last update Wed May 24 01:00:39 2017 Antonin Rapini
*/

#include "sources.h"
#include "utils.h"

float		my_getdist(t_object *objs, sfVector3f eye, sfVector3f dir, int i)
{
  sfVector3f	pos;

  pos = my_add_v3(eye, objs[i].position, -1);
  if (objs[i].type == 1)
    return (intersect_plane(eye, dir));
  if (objs[i].type == 2)
    return (intersect_sphere(pos, dir, objs[i].info));
  if (objs[i].type == 3)
    return (intersect_cylinder(pos, dir, objs[i].info));
  if (objs[i].type == 4)
    return (intersect_cone(pos, dir, objs[i].info));
  return (-1);
}
