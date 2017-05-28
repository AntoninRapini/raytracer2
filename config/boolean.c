/*
** getter.c for  in /home/romain.pillot/projects/ghoulc/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun May 28 17:26:38 2017 romain pillot
** Last update Sun May 28 17:57:52 2017 romain pillot
*/

#include "config.h"
#include "util.h"

bool	get_boolean(t_config *config, const char *path)
{
  t_key	*key;

  key = key_resolve(config->keys, path);
  return (key ? key->boolean : false);
}

bool	keyget_boolean(t_key *key, const char *path)
{
  key = key_resolve((t_array *) key->value, path);
  return (key ? key->boolean : false);
}
