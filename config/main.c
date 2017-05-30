/*
** main.c for  in /home/romain.pillot/projects/ghoulc/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon May 22 14:09:17 2017 romain pillot
** Last update Tue May 30 19:36:13 2017 romain pillot
*/

#include "config.h"
#include "array.h"
#include <stdlib.h>
#include "util.h"
#include <stdio.h>
#include "array.h"

int		main()
{
  t_config	*config;
  t_key		*key;

  config = config_load("res/template.conf");
  key = get_key(config, "key");
  printf("value: %d\n", keyget_boolean(key, "path.test.bool"));
  t_array *array = get_string_array(config, "array.string");
  printf("size: %d\n", array->length);
  int i = -1;
  while (array->values[++i])
    printf("val: %s\n", (char *) array->values[i]);
  config_destroy(config);
  return (0);
}
