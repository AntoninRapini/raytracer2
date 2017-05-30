/*
** free.c for  in /home/romain.pillot/projects/ghoulc/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun May 28 03:15:41 2017 romain pillot
** Last update Tue May 30 14:46:56 2017 romain pillot
*/

#include <stdlib.h>
#include "util.h"
#include "config.h"

static void	key_free(t_key *key)
{
  int		i;
  t_array	*array;
  t_key		**keys;

  if (key->type == KEY_ARRAY)
    {
      array = (t_array *) key->value;
      keys = (t_key **) array->values;
      i = -1;
      while (key && keys[++i])
	key_free(keys[i]);
      FREE(keys);
    }
  else if (key->type == STRING_ARRAY)
    array_destroy((t_array **) &key->value, true);
  else if (key->type == INTEGER_ARRAY)
    FREE(((t_intarray *) key->value)->values);
  FREE(key->name);
  FREE(key->value);
  FREE(key);
}

void		config_destroy(t_config *config)
{
  int		i;
  t_key		**keys;

  keys = (t_key **) config->keys->values;
  i = -1;
  while(keys[++i])
    key_free(keys[i]);
  array_destroy(&config->keys, false);
  FREE(config);
}

void	safe_free(void **ptr)
{
  if (ptr && *ptr)
    {
      free(*ptr);
      *ptr = NULL;
    }
}

void	tab_free(void ***ptr)
{
  if (ptr && *ptr)
    {
      if (**ptr)
	free(**ptr);
      free(*ptr);
      *ptr = NULL;
    }
}
