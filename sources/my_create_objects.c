/*
** my_create_objects.c for raytacer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Mar  8 17:28:16 2017 Antonin Rapini
** Last update Sun May 28 20:42:11 2017 romain pillot
*/

#include "sources.h"

static t_object	*create_object(t_key *key)
{
  t_object	*object;

  if (!(object = malloc(sizeof(t_object))))
    return (NULL);
  object->type = keyget_integer("type");
  object->position = my_create_sfvector3f(keyget_integer("position.x"),
					  keyget_integer("position.y"),
					  keyget_integer("position.z"));
  object->rotation = my_create_sfvector3f(keyget_integer("rotation.x"),
					  keyget_integer("rotation.y"),
					  keyget_integer("rotation.z"));
  object->info = keyget_integer("info");
  object->color.r = keyget_integer("color.r");
  object->color.g = keyget_integer("color.g");
  object->color.b = keyget_integer("color.b");
  object->color.a = keyget_integer("color.a");
  object->brillance = keyget_integer("brillance");
  object->reflection = keyget_integer("reflection");
  object->transparency = keyget_integer("transparency");
  object->refraction_i = keyget_integer("refraction_i");
  return (object);
}

/*
** yolo, dats temporary
*/
static t_object	*convert(t_array *array, t_key **keys, int length)
{
  int		i;
  t_array	*new;

  len = array->length;
  new = malloc(sizeof(t_object * (length + 1)));
  new[len].type = 0;
  i = -1;
  while (++i < len)
    {
      new[i].type = keys[i]->type;
      new[i].position = keys[i]->position;
      new[i].rotation = keys[i]->rotation;
      new[i].info = keys[i]->info;
      new[i].color.r = keys[i]->color.r;
      new[i].color.g = keys[i]->color.g;
      new[i].color.b = keys[i]->color.b;
      new[i].color.a = keys[i]->color.a;
      new[i].brillance = keys[i]->brillance;
      new[i].reflection = keys[i]->reflection;
      new[i].transparency = keys[i]->transparency;
      new[i].refraction_i = keys[i]->refraction_i;
    }
  array_destroy(&array, true);
  return (new);
}

t_object	*my_create_objects(t_config *config)
{
  t_key		*objects;
  t_key		**keys;
  t_array	*array;
  int		i;

  if (!(array = array_create()))
    return (NULL);
  objects = get_key(config, "objects");
  keys = (t_key **) objects->value;
  i = -1;
  while (keys[++i])
    array_add(array, create_object(keys[i]));
  return (convert(array, (t_key **)array->values, array->length));
}
