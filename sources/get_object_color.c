/*
** get_object_color.c for raytracer in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer2/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue May 30 04:33:56 2017 Antonin Rapini
** Last update Wed May 31 04:07:53 2017 Antonin Rapini
*/

#include "sources.h"
#include <math.h>
#include <stdio.h>
#include <math.h>

static UV_FUNC const funcs[] =
  {
    get_plane_uv,
    get_sphere_uv,
    get_cylinder_uv,
    get_cone_uv,
    NULL
  };

sfColor		get_texture_color(t_object *obj, t_ray *ray)
{
  int		i;
  sfColor	color;
  sfVector2f	uv;
  sfVector2i	coords;

  uv.x = 0;
  uv.y = 0;
  i = 0;
  while (funcs[i])
    {
      if (obj->type - 1 == i)
	uv = (funcs[i](obj, ray));
      i++;
    }
  coords.x = uv.x * obj->diffuse_map->size.x;
  coords.y = uv.y * obj->diffuse_map->size.y;
  coords.x = coords.x % obj->diffuse_map->size.x;
  coords.y = coords.y % obj->diffuse_map->size.y;
  color.r = obj->diffuse_map->colors[coords.y][coords.x].r;
  color.g = obj->diffuse_map->colors[coords.y][coords.x].g;
  color.b = obj->diffuse_map->colors[coords.y][coords.x].b;
  color.a = 255;
  return (color);
}

sfColor		get_object_color(t_object *obj, t_ray *ray)
{
  sfColor	color;

  if (obj->materialtype == 1 && obj->type == 1)
    {
      if ((int)fabs(ray->intersect.pos.x) % 40 > 20
	  && (int)fabs(ray->intersect.pos.y) % 40 > 20)
	return (obj->color);
      color.r = 255 - obj->color.r;
      color.g = 255 - obj->color.g;
      color.b = 255 - obj->color.b;
      color.a = 255;
      return (color);
    }
  else if (obj->materialtype == 2)
    return (get_texture_color(obj, ray));
  return (obj->color);
}
