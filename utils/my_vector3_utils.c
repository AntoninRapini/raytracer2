/*
** my_vector3_utils.c for raytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Mar 14 22:16:53 2017 Antonin Rapini
** Last update Sun May 28 22:54:18 2017 Antonin Rapini
*/

#include <SFML/Graphics.h>
#include <math.h>

float my_dot_product(sfVector3f a, sfVector3f b)
{
  return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

sfVector3f	norm_v3(sfVector3f a)
{
  float		norm;

  norm = sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2));
  a.x = a.x / norm;
  a.y = a.y / norm;
  a.z = a.z / norm;
  return (a);
}

sfVector3f my_add_to_v3(sfVector3f a, float value)
{
  a.x += value;
  a.y += value;
  a.z += value;
  return (a);
}

sfVector3f	my_mul_v3(sfVector3f a, float coeff)
{
  a.x = a.x * coeff;
  a.y = a.y * coeff;
  a.z = a.z * coeff;
  return (a);
}

sfVector3f	my_add_v3(sfVector3f a, sfVector3f b, int sign)
{
  sfVector3f	new;

  new.x = a.x + b.x * sign;
  new.y = a.y + b.y * sign;
  new.z = a.z + b.z * sign;
  return (new);
}
