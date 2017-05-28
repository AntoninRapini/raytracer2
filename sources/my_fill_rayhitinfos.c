/*
** my_fill_rayhitinfos.c for raytracer in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer2/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun May 28 00:24:08 2017 Antonin Rapini
** Last update Sun May 28 03:20:00 2017 Antonin Rapini
*/

#include <math.h>
#include "sources.h"
#include <stdio.h>

void my_fill_rayhitinfos
(t_scene *scene, int i, t_intersect *intsct, t_rayhitinfos *infos)
{
  sfColor       background;

  background.r = 120;
  background.g = 140;
  background.b = 170;
  background.a = 255;
  infos->reflection = background;
  infos->light_dir = my_add_v3(scene->lights[i].position, intsct->pos, -1);
  infos->reflection_v = my_get_reflection_vector(infos->light_dir, intsct);
  infos->diffuse = my_get_diffuse_coeff(infos->light_dir, intsct->normal);
  infos->specular = pow(my_dot_product
			(norm_v3(intsct->dir), norm_v3(infos->reflection_v)),
			intsct->obj.brillance);
  infos->shadowed = my_is_shadowed(infos->light_dir,
				   scene, intsct, infos->diffuse);
  infos->distance = my_get_distance(scene->lights[i].position, intsct->pos);
  if (!infos->shadowed && !intsct->reflected)
    if (intsct->obj.reflection != 0)
      infos->reflection = my_get_reflection(intsct, infos->reflection_v, scene);
}
