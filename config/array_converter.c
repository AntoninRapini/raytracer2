/*
** array_converter.c for  in /home/romain.pillot/projects/ghoulc/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue May 30 11:33:15 2017 romain pillot
** Last update Tue May 30 19:57:38 2017 romain pillot
*/

#include <stdlib.h>
#include "config.h"
#include "util.h"

bool	parse_array(t_key *key, const char *value)
{
  char	**split;
  t_key	elem;
  int	i;

  if (!str_contains(value, ","))
    return (false);
  split = str_split(str_dupl(value), ARRAY_SEPARATOR);
  elem.type = UNDEFINED;
  elem.value = NULL;
  parse_value(&elem, split[0]);
  FREE(elem.value);
  key->type = elem.type == INTEGER ? INTEGER_ARRAY :
    elem.type == STRING ? STRING_ARRAY :
    elem.type == BOOLEAN ? BOOLEAN_ARRAY : UNDEFINED;
  if (key->type == INTEGER_ARRAY || key->type == BOOLEAN_ARRAY)
    key->value = create_int_array(split);
  else
    {
      key->value = array_create();
      i = -1;
      while (split[++i])
	array_add((t_array *) key->value, str_dupl(split[i]));
    }
  TAB_FREE(split);
  return (true);
}
