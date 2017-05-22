/*
** my_sphere_intersection.c for 104intersection in /home/antonin.rapini/ModulesTek1/MathematicalProgramming/my104intersection/operations
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Jan  1 16:54:57 2017 Antonin Rapini
** Last update Tue Mar  7 16:54:33 2017 Antonin Rapini
*/

#include <math.h>
#include "sources.h"

float	intersect_cylinder(sfVector3f p, sfVector3f v, float radius)
{
  float a;
  float b;
  float c;

  a = pow(v.x, 2) + pow(v.y, 2);
  b = 2 * (p.x * v.x) + 2 * (v.y * p.y);
  c = pow(p.x, 2) + pow(p.y, 2) - pow(radius, 2);
  return (my_getsolution(a, b, c));
}

sfVector3f get_normal_cylinder(sfVector3f ip)
{
  ip.z = 0;
  return (ip);
}
