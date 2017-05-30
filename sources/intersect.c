/*
** intersect.c for raytracer2 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer2/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon May 29 18:19:25 2017 Antonin Rapini
** Last update Tue May 30 00:13:28 2017 Antonin Rapini
*/

#include "sources.h"

void init_ray(t_ray *ray, sfVector3f dir, sfVector3f origin, int reflections)
{
  ray->direction = dir;
  ray->origin = origin;
  ray->distance = -1;
  ray->reflections = reflections;
}

void	find_intersect(t_object **objs, t_ray *ray, int ignore_index)
{
  int	i;
  float	currdist;

  i = 0;
  currdist = -1;
  while (objs[i])
    {
      if (i != ignore_index)
	{
	  currdist = my_get_dist(objs[i], ray->origin, ray->direction);
	  if (currdist > 0 && (currdist < ray->distance || ray->distance < 0))
	    {
	      ray->distance = currdist;
	      ray->intersect.obj = objs[i];
	      ray->intersect.obj_i = i;
	    }
	}
      i++;
    }
  if (ray->distance == -1)
    return ;
  ray->intersect.pos.x = ray->origin.x + ray->direction.x * ray->distance;
  ray->intersect.pos.y = ray->origin.y + ray->direction.y * ray->distance;
  ray->intersect.pos.z = ray->origin.z + ray->direction.z * ray->distance;
  ray->intersect.normal = my_get_normal(ray->intersect.obj, ray->intersect.pos);
}
