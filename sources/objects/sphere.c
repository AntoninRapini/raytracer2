/*
** intersect_sphere.c for bsraytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/bsraytracer1/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb  8 15:12:25 2017 Antonin Rapini
** Last update Wed May 24 00:40:47 2017 Antonin Rapini
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "sources.h"

float intersect_sphere(sfVector3f p, sfVector3f v, float radius)
{
  float a;
  float b;
  float c;

  a = pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2);
  b = 2 * (p.x * v.x + p.y * v.y + p.z * v.z);
  c = pow(p.x, 2) + pow(p.y, 2) + pow(p.z, 2) - pow(radius, 2);
  return (my_getsolution(a, b, c));
}

sfVector3f get_normal_sphere(sfVector3f pos, sfVector3f ip, float radius)
{
  ip.x = (ip.x - pos.x) / radius;
  ip.y = (ip.y - pos.y) / radius;
  ip.z = (ip.z - pos.z) / radius;
  return (ip);
}
