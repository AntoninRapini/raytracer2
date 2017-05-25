/*
** my_process_light.c for raytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1bonus/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Mar 18 17:53:32 2017 Antonin Rapini
** Last update Fri May 26 00:06:27 2017 Antonin Rapini
*/

#include "sources.h"
#include "utils.h"
#include <math.h>
#include <stdio.h>

sfColor		my_addlight(t_light *light, sfColor color, float angle, float specular)
{
  sfColor	new;

  new.r = color.r * light->brightness * angle + specular * 50;
  new.g = color.g * light->brightness * angle + specular * 50;
  new.b = color.b * light->brightness * angle + specular * 50;
  new.a = 255;
  return (new);
}

sfColor		my_process_light2
(t_light *light, sfColor color, t_intersect *intsct, t_scene *scene)
{
  sfVector3f	dir;
  sfVector3f	reflection_vector;
  float		cos;
  float		angle;
  float		specular;
  int		j;
  int		currdist;
  int		shadowed;
  
  shadowed = 0;
  dir = my_add_v3(light->position, intsct->pos, -1);
  cos = my_dot_product(norm_v3(dir), norm_v3(intsct->normal));
  reflection_vector = my_add_v3(my_mul_v3(norm_v3(intsct->normal), 2 * my_dot_product(norm_v3(dir), norm_v3(intsct->normal))), norm_v3(dir), -1);
  specular = pow(my_dot_product(norm_v3(intsct->dir), norm_v3(reflection_vector)), intsct->obj.brillance);
  angle = acos(cos) * (180 / M_PI);
  j = 0;
  while (scene->objects[j].type)
    {
      if (j != intsct->obji)
	{
	  currdist = my_get_dist(scene->objects + j, intsct->pos, dir);
	  if (currdist >= 0 && currdist <= 1)
	    shadowed++;
	}
      j++;
    }
  if (!shadowed && angle <= 90)
    color = my_addlight(light, intsct->obj.color, cos, specular);
  return (color);
}

sfColor		my_process_light(t_scene *scene, t_intersect *intsct)
{
  int		i;
  sfColor	color;

  color = sfBlack;
  i = 0;
  while (scene->lights[i].brightness)
    {
      color = my_process_light2(scene->lights + i, color, intsct, scene);
      i++;
    }
  color = my_add_colors(color, my_mul_color(intsct->obj.color, 0.2));
  return (color);
}
