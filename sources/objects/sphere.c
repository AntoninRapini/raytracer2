/*
** intersect_sphere.c for bsraytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/bsraytracer1/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb  8 15:12:25 2017 Antonin Rapini
** Last update Sat May 27 16:37:54 2017 Antonin Rapini
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "sources.h"

float	intersect_sphere(t_object *obj, sfVector3f pos, sfVector3f dir)
{
  float a;
  float b;
  float c;

  a = pow(dir.x, 2) + pow(dir.y, 2) + pow(dir.z, 2);
  b = 2 * (pos.x * dir.x + pos.y * dir.y + pos.z * dir.z);
  c = pow(pos.x, 2) + pow(pos.y, 2) + pow(pos.z, 2) - pow(obj->info, 2);
  return (my_getsolution(a, b, c));
}

sfVector3f get_normal_sphere(t_object *obj, sfVector3f ip)
{
  ip.x = (ip.x - obj->position.x) / obj->info;
  ip.y = (ip.y - obj->position.y) / obj->info;
  ip.z = (ip.z - obj->position.z) / obj->info;
  return (ip);
}
