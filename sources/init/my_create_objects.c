/*
** my_create_objects.c for  in /home/romain.pillot/projects/raytracer2
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun May 28 21:44:13 2017 romain pillot
** Last update Thu Jun  1 02:05:04 2017 Antonin Rapini
*/

#include <stdlib.h>
#include <unistd.h>
#include "sources.h"
#include "utils.h"

static void get_limits(t_object *obj, t_key *key)
{
  obj->limited = my_create_sfvector3f(keyget_integer(key, "limited.x"),
					 keyget_integer(key, "limited.y"),
					 keyget_integer(key, "limited.z"));
  obj->max = my_create_sfvector3f(keyget_integer(key, "max.x"),
				     keyget_integer(key, "max.y"),
				     keyget_integer(key, "max.z"));
  obj->min = my_create_sfvector3f(keyget_integer(key, "min.x"),
				     keyget_integer(key, "min.y"),
				     keyget_integer(key, "min.z"));
}

static t_object	*create_object(t_key *key)
{
  t_object	*object;

  if ((object = my_init_object()) == NULL)
    return (NULL);
  object->type = keyget_integer(key, "type");
  object->position = my_create_sfvector3f(keyget_integer(key, "position.x"),
					  keyget_integer(key, "position.y"),
					  keyget_integer(key, "position.z"));
  object->rotation = my_create_sfvector3f(keyget_integer(key, "rotation.x"),
					  keyget_integer(key, "rotation.y"),
					  keyget_integer(key, "rotation.z"));
  object->info = keyget_integer(key, "info");
  object->color = create_color(keyget_integer(key, "color.r"),
			       keyget_integer(key, "color.g"),
			       keyget_integer(key, "color.b"));
  object->brillance = keyget_integer(key, "brillance");
  object->materialtype = keyget_integer(key, "materialtype");
  object->reflection = (float)keyget_integer(key, "reflection") / 100;
  object->transparency = (float)keyget_integer(key, "transparency") / 100;
  object->refraction_i = (float)keyget_integer(key, "refraction_i") / 100;
  object->normal_map_filename = keyget_string(key, "normal_map_filename");
  object->diffuse_map_filename = keyget_string(key, "diffuse_map_filename");
  get_limits(object, key);
  return (object);
}

t_object	**my_create_objects(t_config *config)
{
  t_key		*objects;
  t_array	*keys;
  t_array	*array;
  int		i;

  if (!(array = array_create()) ||
      !(objects = get_key(config, "objects")) ||
      !(keys = (t_array *) objects->value))
    return (NULL);
  i = -1;
  while (((t_key **)keys->values)[++i])
    array_add(array, create_object((t_key *)keys->values[i]));
  return ((t_object **)array->values);
}
