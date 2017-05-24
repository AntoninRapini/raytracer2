/*
** my_sphere_intersection.c for 104intersection in /home/antonin.rapini/ModulesTek1/MathematicalProgramming/my104intersection/operations
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Jan  1 16:54:57 2017 Antonin Rapini
** Last update Wed May 24 22:34:08 2017 Antonin Rapini
*/

#include <math.h>
#include "sources.h"

float	intersect_cone(t_object *obj, sfVector3f pos, sfVector3f dir)
{
  float a;
  float b;
  float c;
  float cte;

  cte = pow(tanf(obj->info * (M_PI / 180)), 2);
  a = pow(dir.x, 2) + pow(dir.y, 2) - (pow(dir.z, 2) * cte);
  b = 2 * (pos.x * dir.x) + 2 * (dir.y * pos.y)
    - ((2 * ((dir.z * pos.z))) * cte);
  c = pow(pos.x, 2) + pow(pos.y, 2) - (pow(pos.z, 2) * cte);
  return (my_getsolution(a, b, c));
}

sfVector3f get_normal_cone(t_object *obj, sfVector3f ip)
{
  ip.z = -tan(obj->info * M_PI / 180) * ip.z;
  return (ip);
}
