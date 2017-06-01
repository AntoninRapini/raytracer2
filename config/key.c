/*
** key.c for  in /home/romain.pillot/projects/ghoulc/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun May 28 04:05:26 2017 romain pillot
** Last update Tue May 30 20:26:27 2017 romain pillot
*/

#include <stdlib.h>
#include "config.h"
#include "util.h"

t_key	*key_resolve(t_array *array, const char *path)
{
  char          **keys;
  int           i;
  t_key         *key;

  keys = str_split(str_dupl(path), KEY_SEPARATOR);
  if (!(key = key_find(array, keys[0])))
    {
      fprint("key resolver: key not found: ");
      fprint(keys[0]);
      fprint("\n");
      TAB_FREE(keys);
      return (false);
    }
  i = 0;
  while (keys[++i])
    if (!(key = key_find((t_array *) key->value, keys[i])))
      {
	fprint("key resolver: key not found: ");
	fprint(keys[i]);
	fprint("\n");
	TAB_FREE(keys);
	return (false);
      }
  TAB_FREE(keys);
  return (key);
}

t_key	*key_find(t_array *array, const char *name)
{
  t_key	**keys;

  keys = array ? (t_key **) array->values : NULL;
  while (keys && *keys++)
    if (str_equals(keys[-1]->name, name))
      return (keys[-1]);
  return (NULL);
}

t_key	*key_create(const char *name, t_keytype type, void *value)
{
  t_key	*key;

  if (!(key = malloc(sizeof(t_key))))
    return (NULL);
  key->name = str_dupl(name);
  key->type = type;
  key->value = value;
  key->boolean = false;
  key->integer = -1;
  return (key);
}

t_key	*get_key(t_config *config, const char *path)
{
  return (key_resolve(config->keys, path));
}

t_key	*keyget_key(t_key *key, const char *path)
{
  return (key_resolve((t_array *) key->value, path));
}
