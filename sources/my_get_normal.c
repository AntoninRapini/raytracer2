/*
** my_get_normal.c for raytracer2 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer2/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed May 24 17:51:04 2017 Antonin Rapini
** Last update Thu Jun  1 04:55:01 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "my_raytracer.h"
#include "sources.h"

static NORMAL_FUNC const funcs[] =
  {
    get_normal_plane,
    get_normal_sphere,
    get_normal_cylinder,
    get_normal_cone,
    NULL
  };

sfVector3f	my_get_normal(t_object *obj, sfVector3f ip)
{
  int		i;
  sfVector3f	normal;
  sfColor	normalcolor;
  sfVector3f	normalrealcolor;

  i = 0;
  while (funcs[i])
    {
      if (obj->type - 1 == i)
	{
	  normal = funcs[i](obj, ip);
	  if (obj->materialtype == 2 && obj->normal_map)
	    {
	      normalcolor = get_texture_color(obj, ip, obj->normal_map);
	      normalrealcolor.x = ((float)normalcolor.r / 255.0f) - 1;
	      normalrealcolor.y = ((float)normalcolor.g / 255.0f) - 1;
	      normalrealcolor.z = ((float)normalcolor.b / 255.0f) - 1;
	      normal.y += normalrealcolor.x
		+ normalrealcolor.y + normalrealcolor.z;
	    }
	  return (normal);
	}
      i++;
    }
  return (get_normal_plane(obj, ip));
}
