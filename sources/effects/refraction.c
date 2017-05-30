/*2z
2z** my_get_reflection.c for raytracer in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer2/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat May 27 23:39:34 2017 Antonin Rapini
** Last update Tue May 30 00:07:48 2017 Antonin Rapini
*/

#include <math.h>
#include "sources.h"

sfVector3f      my_get_refraction_vector
(sfVector3f light_dir, sfVector3f normal, float refraction_i)
{
  sfVector3f    refraction_v;
  sfVector3f    dir_n;
  sfVector3f    normal_n;
  float         a;
  float         n;

  dir_n = norm_v3(light_dir);
  normal_n = norm_v3(normal);
  n = refraction_i / 1;
  refraction_v = my_mul_v3(dir_n, n);
  a = n * my_dot_product(dir_n, normal_n)
    - sqrt((1 + pow(n, 2) * (pow(my_dot_product
                                 (dir_n, normal_n), 2) - 1)));
  refraction_v = my_add_v3(refraction_v, my_mul_v3(normal_n, a), -1);
  return (refraction_v);
}

sfColor         my_get_refraction_color
(t_ray *ray, sfVector3f refraction_v, t_scene *scene)
{
  t_ray         refracted_ray;

  init_ray(&refracted_ray, refraction_v, ray->intersect.pos, 0);
  find_intersect(scene->objects, &refracted_ray, ray->intersect.obj_i);
  if (refracted_ray.distance != -1)
    return (my_process_light(scene, &refracted_ray));
  return (my_get_background());
}
