/*
** get_object_color.c for raytracer in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer2/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue May 30 04:33:56 2017 Antonin Rapini
** Last update Thu Jun  1 04:53:02 2017 Antonin Rapini
*/

#include "sources.h"
#include <math.h>
#include <math.h>

static UV_FUNC const funcs[] =
  {
    get_plane_uv,
    get_sphere_uv,
    get_cylinder_uv,
    get_cone_uv,
    NULL
  };

sfColor		get_texture_color(t_object *obj, sfVector3f ip, t_texture *map)
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
	uv = (funcs[i](obj, ip));
      i++;
    }
  coords.x = uv.x * map->size.x;
  coords.y = uv.y * map->size.y;
  coords.x = coords.x % map->size.x;
  coords.y = coords.y % map->size.y;
  color.r = map->colors[coords.y][coords.x].r;
  color.g = map->colors[coords.y][coords.x].g;
  color.b = map->colors[coords.y][coords.x].b;
  color.a = map->colors[coords.y][coords.x].a;
  return (color);
}

sfColor		apply_perlin(t_object *obj, t_ray *ray)
{
  sfColor	color;
  float		perlin;

  perlin = cos (ray->intersect.pos.x + perlin_noise(ray->intersect.pos.x,
						    ray->intersect.pos.y, 0.05, 2));
  color.r = obj->color.r * perlin;
  color.g = obj->color.g * perlin;
  color.b = obj->color.b * perlin;
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
    return (get_texture_color(obj, ray->intersect.pos, obj->diffuse_map));
  else if (obj->materialtype == 3)
    return (apply_perlin(obj, ray));
  return (obj->color);
}
