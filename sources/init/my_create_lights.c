/*
** my_create_lights.c for raytracer2 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer2/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon May 29 17:08:37 2017 Antonin Rapini
** Last update Tue May 30 20:24:27 2017 romain pillot
*/

#include <stdlib.h>
#include "sources.h"
#include "utils.h"

static t_light *create_light(t_key *key)
{
  t_light	*light;

  if (!(light = malloc(sizeof(t_light))))
    return (NULL);
  light->position = my_create_sfvector3f(keyget_integer(key, "position.x"),
					 keyget_integer(key, "position.y"),
					 keyget_integer(key, "position.z"));
  light->rotation = my_create_sfvector3f(keyget_integer(key, "rotation.x"),
					 keyget_integer(key, "rotation.y"),
					 keyget_integer(key, "rotation.z"));
  light->color = create_color(keyget_integer(key, "color.r"),
			      keyget_integer(key, "color.g"),
			      keyget_integer(key, "color.b"));
  light->specular = (float)keyget_integer(key, "specular") / 100;
  light->diffuse = (float)keyget_integer(key, "diffuse") / 100;
  light->brightness = (float)keyget_integer(key, "brightness") / 100;
  return (light);
}

t_light		**my_create_lights(t_config *config)
{
  t_key		*lights;
  t_array	*keys;
  t_array	*array;
  int		i;

  if (!(array = array_create()) ||
      (lights = get_key(config, "lights")) == NULL ||
      !(keys =  (t_array *) lights->value))
    return (NULL);
  i = -1;
  while (((t_key **) keys->values)[++i])
    array_add(array, create_light((t_key *) keys->values[i]));
  return ((t_light **)array->values);
}
