/*
** config.h for  in /home/romain.pillot/projects/ghoulc
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon May 22 16:07:46 2017 romain pillot
** Last update Tue May 30 19:33:13 2017 romain pillot
*/

#ifndef CONFIG_H_
# define CONFIG_H_

# include <stdbool.h>
# include "array.h"

# define KEY_SEPARATOR		('.')
# define VALUE_SEPARATOR	(':')
# define VALUE_SEPARATOR_STRING	(":")
# define ARRAY_SEPARATOR	(',')

typedef enum	e_keytype
{
  KEY_ARRAY,
  INTEGER,
  STRING,
  BOOLEAN,
  STRING_ARRAY,
  INTEGER_ARRAY,
  BOOLEAN_ARRAY,
  UNDEFINED
}		t_keytype;

typedef struct	s_intarray
{
  int		*values;
  int		length;
}		t_intarray;

typedef struct	s_key
{
  char		*name;
  t_keytype	type;
  void		*value;
  bool		boolean;
  int		integer;
}		t_key;

typedef struct	s_config
{
  const char	*name;
  t_array	*keys;
}		t_config;

t_intarray	*get_int_array(t_config *config, const char *path);

t_intarray	*keyget_int_array(t_key *key, const char *path);

t_array		*get_string_array(t_config *config, const char *path);

t_array		*keyget_string_array(t_key *key, const char *path);

t_key		*get_key(t_config *config, const char *path);

t_key		*keyget_key(t_key *key, const char *path);

char		*get_string(t_config *config, const char *path);

char		*keyget_string(t_key *key, const char *path);

int		get_integer(t_config *config, const char *path);

int		keyget_integer(t_key *key, const char *path);

bool		get_boolean(t_config *config, const char *path);

bool		keyget_boolean(t_key *key, const char *path);

t_key		*key_resolve(t_array *array, const char *path);

t_key		*key_find(t_array *array, const char *name);

t_key		*key_create(const char *name, t_keytype type, void *value);

t_intarray	*create_int_array(char * const *values);

bool		parse_array(t_key *key, const char *value);

void		parse_value(t_key *key, const char *value);

t_config	*config_load(const char *file_name);

void		config_destroy(t_config *config);

#endif /* !CONFIG_H_ */
