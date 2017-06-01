/*
** my_get_reflection.c for raytracer in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer2/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat May 27 23:39:34 2017 Antonin Rapini
** Last update Thu Jun  1 03:57:46 2017 Antonin Rapini
*/

#include "sources.h"

sfVector3f      my_get_reflection_vector
(sfVector3f light_dir, sfVector3f normal)
{
  sfVector3f    reflection_v;
  sfVector3f    dir_n;
  sfVector3f    normal_n;

  dir_n = norm_v3(light_dir);
  normal_n = norm_v3(normal);
  reflection_v = my_add_v3(my_mul_v3
			   (normal_n, 2 * my_dot_product
			    (dir_n, normal_n)), dir_n, -1);
  return (reflection_v);
}

sfColor		my_get_reflection_color
(t_ray *ray, sfVector3f reflection_v, t_scene *scene)
{
  t_ray		reflected_ray;

  init_ray(&reflected_ray, reflection_v,
	      ray->intersect.pos, ray->reflections + 1);
  find_intersect(scene->objects, &reflected_ray, ray->intersect.obj_i);
  if (reflected_ray.distance != -1)
    return (my_process_light(scene, &reflected_ray));
  return (scene->background);
}
