/*
** my_process_light.c for raytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1bonus/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Mar 18 17:53:32 2017 Antonin Rapini
** Last update Thu Jun  1 05:00:57 2017 Antonin Rapini
*/

#include "sources.h"
#include "utils.h"
#include <math.h>

sfColor		my_addlight
(t_lightray *infos, t_light *light, t_object *obj, t_ray *ray)
{
  sfVector3f	color;
  sfColor	objcolor;
  float		transparency;

  objcolor = get_object_color(obj, ray);
  transparency = objcolor.a == 0 ? 1 : obj->transparency;
  color.x = (objcolor.r + light->color.r);
  color.y = (objcolor.g + light->color.g);
  color.z = (objcolor.b + light->color.b);
  color = my_mul_v3(color, light->brightness *
		    (light->diffuse * infos->diffuse
		     + light->specular * infos->specular));
  color = my_mul_v3(color, (1 - obj->reflection));
  color = my_mul_v3(color, (1 - transparency));
  color.x += (infos->reflection.r * obj->reflection);
  color.y += (infos->reflection.g * obj->reflection);
  color.z += (infos->reflection.b * obj->reflection);
  color.x += (infos->refraction.r * transparency);
  color.y += (infos->refraction.g * transparency);
  color.z += (infos->refraction.b * transparency);
  color = my_mul_v3(color, (float)(1 - (float)infos->shadow / 100));
  objcolor.r = color.x > 255 ? 255 : color.x < 0 ? 0 : color.x;
  objcolor.g = color.y > 255 ? 255 : color.y < 0 ? 0 : color.y;
  objcolor.b = color.z > 255 ? 255 : color.z < 0 ? 0 : color.z;
  return (objcolor);
}

sfColor		my_process_light(t_scene *scene, t_ray *ray)
{
  int		i;
  sfColor	color;
  sfColor	newcolor;
  t_lightray	lightray;

  newcolor = sfBlack;
  color = my_mul_color(get_object_color(ray->intersect.obj, ray), 0.2
		       * (1 - ray->intersect.obj->transparency));
  i = 0;
  while (scene->lights[i])
    {
      fill_lightray(scene, scene->lights[i], ray, &lightray);
      newcolor = my_add_colors
	(newcolor, my_addlight(&lightray,
			       scene->lights[i], ray->intersect.obj, ray));
      i++;
    }
  color = my_add_colors(color, newcolor);
  return (color);
}
