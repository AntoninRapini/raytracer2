/*
** integer.c for  in /home/romain.pillot/projects/ghoulc/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun May 28 17:58:31 2017 romain pillot
** Last update Tue May 30 13:01:21 2017 romain pillot
*/

#include "config.h"
#include "util.h"
#include <stdint.h>

int	get_integer(t_config *config, const char *path)
{
  t_key *key;

  key = key_resolve(config->keys, path);
  return (key ? key->integer : -1);
}

int	keyget_integer(t_key *key, const char *path)
{
  key = key_resolve((t_array *) key->value, path);
  return (key ? key->integer : -1);
}
