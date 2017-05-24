/*
** my_get_normal.c for raytracer2 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer2/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed May 24 17:51:04 2017 Antonin Rapini
** Last update Wed May 24 22:37:02 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "my_raytracer.h"

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

  i = 0;
  while (funcs[i])
    {
      if (obj->type - 1 == i)
	return (funcs[i](obj, ip));
      i++;
    }
  return (get_normal_plane(obj, ip));
}
