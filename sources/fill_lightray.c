/*
** my_fill_rayhitinfos.c for raytracer in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer2/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun May 28 00:24:08 2017 Antonin Rapini
** Last update Tue May 30 20:43:47 2017 Antonin Rapini
*/

#include <math.h>
#include "sources.h"

void fill_lightray
(t_scene *scene, t_light *light, t_ray *ray, t_lightray *lray)
{
  lray->light_dir = my_add_v3(light->position, ray->intersect.pos, -1);
  lray->reflection_v = my_get_reflection_vector
    (lray->light_dir, ray->intersect.normal);
  lray->refraction_v = my_get_refraction_vector
    (lray->light_dir, ray->intersect.normal,
     ray->intersect.obj->refraction_i);
  lray->diffuse = my_get_diffuse_coeff(lray->light_dir, ray->intersect.normal);
  lray->specular = pow(my_dot_product
			(norm_v3(ray->direction),
			 norm_v3(lray->reflection_v)),
			ray->intersect.obj->brillance);
  lray->shadow = my_get_shadow(lray, scene, &(ray->intersect));
  lray->distance = euclidean_distance(light->position, ray->intersect.pos);
  if (ray->reflections < 3)
    lray->refraction = my_get_reflection_color
      (ray, ray->direction, scene);
  if (ray->reflections < 3 && ray->intersect.obj->reflection != 0)
    lray->reflection = my_get_reflection_color
      (ray, lray->reflection_v, scene);
}
