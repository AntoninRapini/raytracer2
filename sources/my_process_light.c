/*
** my_process_light.c for raytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1bonus/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Mar 18 17:53:32 2017 Antonin Rapini
** Last update Sun May 28 23:29:55 2017 Antonin Rapini
*/

#include "sources.h"
#include "utils.h"
#include <math.h>
#include <stdio.h>

sfColor		my_addlight(t_rayhitinfos *infos, t_light *light, t_object *obj)
{
  sfColor	new;
  sfVector3f	color;

  color.x = (obj->color.r + light->color.r);
  color.y = (obj->color.g + light->color.g);
  color.z = (obj->color.b + light->color.b);
  color = my_mul_v3(color, light->brightness *
		    (light->diffuse * infos->diffuse
		     + light->specular * infos->specular));
  color = my_mul_v3(color, (1 - obj->reflection));
  color = my_mul_v3(color, (1 - obj->transparency));
  color.x += (infos->reflection.r * obj->reflection);
  color.y += (infos->reflection.g * obj->reflection);
  color.z += (infos->reflection.b * obj->reflection);
  color.x += (infos->refraction.r * obj->transparency);
  color.y += (infos->refraction.g * obj->transparency);
  color.z += (infos->refraction.b * obj->transparency);
  color = my_mul_v3(color, (float)(1 - (float)infos->shadow / 100));
  new.a = 255;
  new.r = color.x > 255 ? 255 : color.x < 0 ? 0 : color.x;
  new.g = color.y > 255 ? 255 : color.y < 0 ? 0 : color.y;
  new.b = color.z > 255 ? 255 : color.z < 0 ? 0 : color.z;
  return (new);
}

sfColor		my_process_light(t_scene *scene, t_intersect *intsct)
{
  int		i;
  sfColor	color;
  sfColor	newcolor;
  t_rayhitinfos	rayhitinfos;

  newcolor = sfBlack;
  color = my_mul_color(intsct->obj.color, 0.2 * (1 - intsct->obj.transparency));
  i = 0;
  while (scene->lights[i].brightness)
    {
      my_fill_rayhitinfos(scene, i, intsct, &rayhitinfos);
      newcolor = my_add_colors
	(newcolor, my_addlight(&rayhitinfos,
			       scene->lights + i, &(intsct->obj)));
      i++;
    }
  color = my_add_colors(color, newcolor);
  return (color);
}
