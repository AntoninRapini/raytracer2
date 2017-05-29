/*
** my_phong_utils.c for raytracer2 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer2/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat May 27 16:53:36 2017 Antonin Rapini
** Last update Tue May 30 00:08:28 2017 Antonin Rapini
*/

#include <math.h>
#include "sources.h"

float	my_get_diffuse_coeff(sfVector3f light_dir, sfVector3f normal)
{
  float	diffuse;

  diffuse = my_dot_product(norm_v3(light_dir), norm_v3(normal));
  return (diffuse < 0 ? 0 : diffuse > 1 ? 1 : diffuse);
}

float euclidean_distance(sfVector3f a, sfVector3f b)
{
  return (sqrt(powf(b.x - a.x, 2) + powf(b.y - a.y, 2) + powf(b.z - a.z, 2)));
}

int	my_get_shadow(t_lightray *lray, t_scene *scene, t_intersect *intsct)
{
  int	i;
  float	currdist;
  int	shadow;

  shadow = 0;
  i = 0;
  if (acos(lray->diffuse) * (180 / M_PI) >= 90)
    return (1);
  while (scene->objects[i])
    {
      if (i != intsct->obj_i)
	{
	  currdist = my_get_dist(scene->objects[i], intsct->pos, lray->light_dir);
	  if (currdist >= 0 && currdist <= 1)
	    {
	      shadow += 100 - scene->objects[i]->transparency * 100;
	      if (shadow >= 100)
		return (100);
	    }
	}
      i++;
    }
  return (shadow);
}
