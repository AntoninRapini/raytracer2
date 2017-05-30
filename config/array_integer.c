/*
** array_integer.c for  in /home/romain.pillot/projects/ghoulc/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue May 30 13:48:25 2017 romain pillot
** Last update Tue May 30 14:14:15 2017 romain pillot
*/

#include <stdlib.h>
#include "config.h"
#include "util.h"

t_intarray	*get_int_array(t_config *config, const char *path)
{
  t_key *key;

  key = key_resolve(config->keys, path);
  return (key ? key->value : NULL);
}

t_intarray	*keyget_int_array(t_key *key, const char *path)
{
  key = key_resolve((t_array *) key->value, path);
  return (key ? key->value : NULL);
}

t_intarray	*create_int_array(char * const *values)
{
  t_intarray	*array;
  int		i;

  if (!(array = malloc(sizeof(t_intarray))))
    return (NULL);
  array->length = 0;
  while (values && values[array->length] && ++(array->length));
  array->values = malloc(sizeof(int) * array->length);
  i = -1;
  while (++i < array->length)
    array->values[i] = nbr_parsestring(values[i]);
  return (array);
}
