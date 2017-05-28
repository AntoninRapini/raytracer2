/*
** my_create_objects.c for raytacer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Mar  8 17:28:16 2017 Antonin Rapini
** Last update Sun May 28 20:17:54 2017 romain pillot
*/

#include "config.h"

int my_fill_objectinfos(int *infos, int i, t_object *objs)
{
  objs[i].type = infos[0];
  objs[i].position = my_create_sfvector3f(infos[1], infos[2], infos[3]);
  objs[i].rotation = my_create_sfvector3f(infos[4], infos[5], infos[6]);
  objs[i].info = infos[7];
  objs[i].color.r = infos[8];
  objs[i].color.g = infos[9];
  objs[i].color.b = infos[10];
  objs[i].color.a = infos[11];
  objs[i].brillance = (float)infos[12];
  objs[i].reflection = (float)infos[13] / 100;
  objs[i].transparency = infos[14] / 100;
  if (objs[i].type > 4 || objs[i].type < 1)
    return (1);
  return (0);
}

t_object	*create_object(t_key *key)
{
  t_object	*object;

  if (!(object = malloc(sizeof(t_object))))
    return (NULL);
  
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
  return (array);
}
