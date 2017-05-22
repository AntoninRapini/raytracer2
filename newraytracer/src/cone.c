/*
** my_sphere_intersection.c for 104intersection in /home/antonin.rapini/ModulesTek1/MathematicalProgramming/my104intersection/operations
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Jan  1 16:54:57 2017 Antonin Rapini
** Last update Wed Mar 15 17:14:25 2017 Antonin Rapini
*/

#include <math.h>
#include "sources.h"

float	intersect_cone(sfVector3f p, sfVector3f v, float angle)
{
  float a;
  float b;
  float c;
  float cte;

  cte = pow(tanf(angle * (M_PI / 180)), 2);
  a = pow(v.x, 2) + pow(v.y, 2) - (pow(v.z, 2) * cte);
  b = 2 * (p.x * v.x) + 2 * (v.y * p.y) - ((2 * ((v.z * p.z))) * cte);
  c = pow(p.x, 2) + pow(p.y, 2) - (pow(p.z, 2) * cte);
  return (my_getsolution(a, b, c));
}

sfVector3f get_normal_cone(sfVector3f ip, float angle)
{
  ip.z = -tan(angle * M_PI / 180) * ip.z;
  return (ip);
}
