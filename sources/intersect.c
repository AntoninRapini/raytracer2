/*
** intersect.c for raytracer2 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer2/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon May 29 18:19:25 2017 Antonin Rapini
** Last update Thu Jun  1 00:01:16 2017 Antonin Rapini
*/

#include "sources.h"
#include <stdio.h>

void init_ray(t_ray *ray, sfVector3f dir, sfVector3f origin, int reflections)
{
  ray->direction = dir;
  ray->origin = origin;
  ray->distance = -1;
  ray->reflections = reflections;
}

int fix_limited(t_ray *ray, t_object *obj, float dist)
{
  ray->intersect.pos.x = ray->origin.x + ray->direction.x * dist;
  ray->intersect.pos.y = ray->origin.y + ray->direction.y * dist;
  ray->intersect.pos.z = ray->origin.z + ray->direction.z * dist;
  if (obj->limited.x != 0 && (ray->intersect.pos.x > obj->max.x
			      + obj->position.x || ray->intersect.pos.x
			      < obj->min.x + obj->position.x))
    return (1);
  if (obj->limited.y != 0 && (ray->intersect.pos.y > obj->max.y
			      + obj->position.y || ray->intersect.pos.y
			      < obj->min.y + obj->position.y))
    return (1);
  if (obj->limited.z != 0 && (ray->intersect.pos.z > obj->max.z
			      + obj->position.z || ray->intersect.pos.z
			      < obj->min.z + obj->position.z))
    return (1);
  return (0);
}

void	find_intersect(t_object **objs, t_ray *ray, int ignore_index)
{
  int	i;
  float	currdist;

  i = 0;
  currdist = -1;
  while (objs[i++])
    {
      if (i - 1 != ignore_index)
	{
	  currdist = my_get_dist(objs[i - 1], ray->origin, ray->direction);
	  if ((currdist > 0 && (currdist < ray->distance || ray->distance < 0)) &&
	      fix_limited(ray, objs[i - 1], currdist) == 0)
	    {
	      ray->distance = currdist;
	      ray->intersect.obj = objs[i - 1];
	      ray->intersect.obj_i = i - 1;
	    }
	}
    }
  if (ray->distance != -1)
    ray->intersect.normal = my_get_normal(ray->intersect.obj,
					  ray->intersect.pos);
}
