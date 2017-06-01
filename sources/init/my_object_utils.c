/*
** my_objects_utils.c for raytracer2 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer2/sources/init
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed May 31 23:11:01 2017 Antonin Rapini
** Last update Thu Jun  1 01:36:45 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "sources.h"
#include "utils.h"

void	*my_free_object(t_object *obj)
{
  if (obj)
    {
      if (obj->diffuse_map_filename)
	free(obj->diffuse_map_filename);
      my_free_texture(obj->diffuse_map);
      free(obj);
    }
  return (NULL);
}

void	*my_free_objects(t_object **objs)
{
  int	i;

  i = 0;
  if (objs)
    {
      while (objs[i])
	{
	  my_free_object(objs[i]);
	  i++;
	}
      free(objs);
    }
  return (NULL);
}

t_object	*my_init_object()
{
  t_object	*object;

  if ((object = malloc(sizeof(t_object))) == NULL)
    return (NULL);
  object->type = 0;
  object->position = my_create_sfvector3f(0, 0, 0);
  object->rotation = my_create_sfvector3f(0, 0, 0);
  object->color = create_color(0, 0, 0);
  object->info = 0;
  object->brillance = 0;
  object->materialtype = 0;
  object->transparency = 0;
  object->refraction_i = 0;
  object->reflection = 0;
  object->diffuse_map_filename = NULL;
  object->diffuse_map = NULL;
  object->normal_map_filename = NULL;
  object->normal_map = NULL;
  object->limited = my_create_sfvector3f(0, 0, 0);
  object->max = my_create_sfvector3f(0, 0, 0);
  object->min = my_create_sfvector3f(0, 0, 0);
  return (object);
}
