/*
** my_phong_utils.c for raytracer2 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer2/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat May 27 16:53:36 2017 Antonin Rapini
** Last update Sun May 28 19:32:08 2017 Antonin Rapini
*/

#include <math.h>
#include "sources.h"

float	my_get_diffuse_coeff(sfVector3f light_dir, sfVector3f normal)
{
  float	diffuse;

  diffuse = my_dot_product(norm_v3(light_dir), norm_v3(normal));
  return (diffuse < 0 ? 0 : diffuse > 1 ? 1 : diffuse);
}

float my_get_distance(sfVector3f a, sfVector3f b)
{
  return (sqrt(powf(b.x - a.x, 2) + powf(b.y - a.y, 2) + powf(b.z - a.z, 2)));
}

sfVector3f	my_get_refraction_vector(sfVector3f light_dir, t_intersect *intsct)
{
  sfVector3f	refraction_v;
  sfVector3f	dir_n;
  sfVector3f	normal_n;
  float		b;
  float		n;

  dir_n = norm_v3(light_dir);
  normal_n = norm_v3(intsct->normal);
  n = intsct->obj.refraction_i / 1;
  refraction_v = my_mul_v3(dir_n, n);
  b = n * my_dot_product(dir_n, normal_n) - sqrt((1 + pow(n, 2) * (pow(my_dot_product(dir_n, normal_n), 2) - 1)));
  refraction_v = my_add_v3(refraction_v, my_mul_v3(normal_n, b), -1);
  return (refraction_v);
}

sfVector3f	my_get_reflection_vector(sfVector3f light_dir, t_intersect *intsct)
{
  sfVector3f	reflection_v;
  sfVector3f	dir_n;
  sfVector3f	normal_n;

  dir_n = norm_v3(light_dir);
  normal_n = norm_v3(intsct->normal);
  reflection_v = my_add_v3(my_mul_v3(normal_n,
				     2 * my_dot_product(dir_n, normal_n)), dir_n, -1);
  return (reflection_v);
}

int	my_is_shadowed
(sfVector3f light_dir, t_scene *scene, t_intersect *intsct, float diffuse)
{
  int	j;
  float	currdist;

  j = 0;
  if (acos(diffuse) * (180 / M_PI) >= 90)
    return (1);
  while (scene->objects[j].type)
    {
      if (j != intsct->obji)
	{
	  currdist = my_get_dist(scene->objects + j, intsct->pos, light_dir);
	  if (currdist >= 0 && currdist <= 1 && scene->objects[j].transparency == 0)
	    return (1);
	}
      j++;
    }
  return (0);
}
