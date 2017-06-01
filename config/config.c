/*
** config.c for  in /home/romain.pillot/projects/ghoulc/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue May 23 13:46:43 2017 romain pillot
** Last update Thu Jun  1 09:39:13 2017 Raphaël Goulmot
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "config.h"
#include "util.h"
#include "array.h"

static bool	open_file(const char *file_name, int *fd)
{
  if ((*fd = open(file_name, O_RDONLY)) == -1)
    fprint("open_file: can't read the given file name.");
  return (*fd != -1);
}

static t_key	*apply_strategy(t_key *key, char **keys, int i)
{
  t_key		*found;

  if (!key->value)
    {
      key->value = array_create();
      key->type = KEY_ARRAY;
    }
  if (!(found = key_find(key->value, keys[i])))
    {
      found = key_create(keys[i], UNDEFINED, NULL);
      array_add((t_array *) key->value, found);
    }
  return (found);
}

void	parse_value(t_key *key, const char *value)
{
  bool	b;
  int	i;

  b = false;
  if ((b = str_equals(value, "yes")) || str_equals(value, "no") ||
      (b = str_equals(value, "true")) || str_equals(value, "false"))
    {
      key->type = BOOLEAN;
      key->boolean = b;
      return ;
    }
  i = -1;
  while (value[++i])
    if (value[i] != '-' && !(value[i] >= '0' && value[i] <= '9'))
      {
	if (parse_array(key, value))
	  return ;
	key->type = STRING;
	key->value = str_dupl(value);
	return ;
      }
  key->integer = key->type == UNDEFINED ? nbr_parsestring(value) : key->integer;
  key->type = key->type == UNDEFINED ? INTEGER : key->type;
}

static void	parse_line(t_config *config, const char *str)
{
  char		**pair;
  char		**keys;
  int		i;
  t_key		*key;

  pair = str_split(str_dupl(str), VALUE_SEPARATOR);
  if (pair && pair[0] && pair[1])
    {
      keys = str_split(pair[0], KEY_SEPARATOR);
      if (!(key = key_find(config->keys, keys[0])))
	{
	  key = key_create(keys[0], UNDEFINED, NULL);
	  array_add(config->keys, key);
	}
      i = 0;
      while (keys[++i])
	key = apply_strategy(key, keys, i);
      parse_value(key, str_reduce(pair[1], ' '));
    }
  TAB_FREE(pair);
  FREE(keys);
}

t_config	*config_load(const char *file_name)
{
  t_config	*config;
  int		fd;
  char		*str;

  if (!open_file(file_name, &fd) ||
      !(config = malloc(sizeof(t_config))))
    return (NULL);
  config->name = file_name;
  config->keys = array_create();
  while ((str = str_reduce(scan_line(fd), ' ')))
    {
      if (*str && str_contains(str, (char [2]){VALUE_SEPARATOR, 0}))
	parse_line(config, str);
      free(str);
    }
  close(fd);
  return (config);
}
