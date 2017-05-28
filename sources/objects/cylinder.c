/*
** my_sphere_intersection.c for 104intersection in /home/antonin.rapini/ModulesTek1/MathematicalProgramming/my104intersection/operations
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Jan  1 16:54:57 2017 Antonin Rapini
** Last update Sat May 27 16:49:44 2017 Antonin Rapini
*/

#include <math.h>
#include "sources.h"

float	intersect_cylinder(t_object *obj, sfVector3f pos, sfVector3f dir)
{
  float a;
  float b;
  float c;

  a = pow(dir.x, 2) + pow(dir.y, 2);
  b = 2 * (pos.x * dir.x) + 2 * (dir.y * pos.y);
  c = pow(pos.x, 2) + pow(pos.y, 2) - pow(obj->info, 2);
  return (my_getsolution(a, b, c));
}

sfVector3f	get_normal_cylinder(t_object *obj, sfVector3f ip)
{
  sfVector3f	tmp;

  tmp.x = ip.x - obj->position.x;
  tmp.y = ip.y - obj->position.y;
  tmp.z = 0;
  return (tmp);
}
