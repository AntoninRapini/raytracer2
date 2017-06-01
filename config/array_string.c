/*
** array_string.c for  in /home/romain.pillot/projects/ghoulc/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue May 30 14:14:49 2017 romain pillot
** Last update Tue May 30 14:15:19 2017 romain pillot
*/

#include <stdlib.h>
#include "config.h"
#include "util.h"

t_array      *get_string_array(t_config *config, const char *path)
{
  t_key *key;

  key = key_resolve(config->keys, path);
  return (key ? key->value : NULL);
}

t_array      *keyget_string_array(t_key *key, const char *path)
{
  key = key_resolve((t_array *) key->value, path);
  return (key ? key->value : NULL);
}
