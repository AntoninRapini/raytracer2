/*
** string.c for  in /home/romain.pillot/projects/ghoulc/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun May 28 18:01:36 2017 romain pillot
** Last update Sun May 28 18:07:18 2017 romain pillot
*/

#include <stdlib.h>
#include "config.h"
#include "util.h"

char	*get_string(t_config *config, const char *path)
{
  t_key *key;

  key = key_resolve(config->keys, path);
  return (key ? str_dupl(key->value) : NULL);
}

char	*keyget_string(t_key *key, const char *path)
{
  key = key_resolve((t_array *) key->value, path);
  return (key ? str_dupl(key->value) : NULL);
}
