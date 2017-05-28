/*
** my_process_light.c for raytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1bonus/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Mar 18 17:53:32 2017 Antonin Rapini
** Last update Sun May 28 16:07:08 2017 Antonin Rapini
*/

#include "sources.h"
#include "utils.h"
#include <math.h>
#include <stdio.h>

sfColor		my_addlight(t_rayhitinfos *infos, t_light *light, t_object *obj)
{
  sfColor	new;
  int		r;
  int		g;
  int		b;
  /*float		attenuation;

    attenuation = 1 / 1 + (pow(infos->distance, 2) * 0.0000001);*/
  r = ((obj->color.r + light->color.r) * (1 - obj->reflection)) + (infos->reflection.r * obj->reflection);
  g = ((obj->color.g + light->color.g) * (1 - obj->reflection)) + (infos->reflection.g * obj->reflection);
  b = ((obj->color.b + light->color.b) * (1 - obj->reflection)) + (infos->reflection.b * obj->reflection);
  r *= (light->brightness * (light->diffuse * infos->diffuse + light->specular * infos->specular));
  g *= (light->brightness * (light->diffuse * infos->diffuse + light->specular * infos->specular));
  b *= (light->brightness * (light->diffuse * infos->diffuse + light->specular * infos->specular));
  new.a = 255;
  new.r = r > 255 ? 255 : r < 0 ? 0 : r;
  new.g = g > 255 ? 255 : g < 0 ? 0 : g;
  new.b = b > 255 ? 255 : b < 0 ? 0 : b;
  return (new);
}

sfColor		my_process_light(t_scene *scene, t_intersect *intsct)
{
  int		i;
  sfColor	color;
  sfColor	newcolor;
  t_rayhitinfos	rayhitinfos;

  newcolor = sfBlack;
  color = my_mul_color(intsct->obj.color, 0.2);
  i = 0;
  while (scene->lights[i].brightness)
    {
      my_fill_rayhitinfos(scene, i, intsct, &rayhitinfos);
      if (!rayhitinfos.shadowed)
	{
	  newcolor = my_add_colors(newcolor,
				   my_addlight(&rayhitinfos, scene->lights + i, &(intsct->obj)));
	}
      i++;
    }
  color = my_add_colors(color, newcolor);
  return (color);
}
