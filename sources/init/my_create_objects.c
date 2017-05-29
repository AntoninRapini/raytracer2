/*
** my_create_objects.c for  in /home/romain.pillot/projects/raytracer2
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun May 28 21:44:13 2017 romain pillot
** Last update Tue May 30 00:55:20 2017 Antonin Rapini
*/

#include <stdlib.h>
#include <unistd.h>
#include "sources.h"
#include "utils.h"

static t_object	*create_object(t_key *key)
{
  t_object	*object;

  if (!(object = malloc(sizeof(t_object))))
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
  object->reflection = (float)keyget_integer(key, "reflection") / 100;
  object->transparency = (float)keyget_integer(key, "transparency") / 100;
  object->refraction_i = (float)keyget_integer(key, "refraction_i") / 100;
  return (object);
}

/* temporary
static t_object	*convert(t_array *array, t_object **objs, int length)
{
  int		i;
  t_object	*new;

  if (!(new = malloc(sizeof(t_object) * (length + 1))))
    return (NULL);
  new[length].type = 0;
  i = -1;
  while (++i < length)
    {
      new[i].type = objs[i]->type;
      new[i].position = objs[i]->position;
      new[i].rotation = objs[i]->rotation;
      new[i].info = objs[i]->info;
      new[i].color.r = objs[i]->color.r;
      new[i].color.g = objs[i]->color.g;
      new[i].color.b = objs[i]->color.b;
      new[i].color.a = objs[i]->color.a;
      new[i].brillance = objs[i]->brillance;
      new[i].reflection = objs[i]->reflection;
      new[i].transparency = objs[i]->transparency;
      new[i].refraction_i = objs[i]->refraction_i;
    }
  array_destroy(&array, true);
  return (new);
  }*/

t_object	**my_create_objects(t_config *config)
{
  t_key		*objects;
  t_array	*keys;
  t_array	*array;
  int		i;

  if (!(array = array_create()))
    return (NULL);
  objects = get_key(config, "objects");
  keys = (t_array *) objects->value;
  i = -1;
  while (((t_key **) keys->values)[++i])
    array_add(array, create_object((t_key *) keys->values[i]));
  return ((t_object **)array->values);
}
