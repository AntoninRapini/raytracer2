/*
** my_create_objects.c for raytacer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Mar  8 17:28:16 2017 Antonin Rapini
** Last update Sun May 28 21:59:39 2017 Antonin Rapini
*/

#include "sources.h"
#include "utils.h"
#include "my_object.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int my_fill_objectinfos(int *infos, int i, t_object *objs)
{
  objs[i].type = infos[0];
  objs[i].position = my_create_sfvector3f(infos[1], infos[2], infos[3]);
  objs[i].rotation = my_create_sfvector3f(infos[4], infos[5], infos[6]);
  objs[i].info = infos[7];
  objs[i].color.r = infos[8];
  objs[i].color.g = infos[9];
  objs[i].color.b = infos[10];
  objs[i].color.a = infos[11];
  objs[i].brillance = (float)infos[12];
  objs[i].reflection = (float)infos[13] / 100;
  objs[i].transparency = (float)infos[14] / 100;
  objs[i].refraction_i = (float)infos[15] / 100;
  if (objs[i].type > 4 || objs[i].type < 1)
    return (1);
  return (0);
}

int		my_parse_objectline
(char *buffer, t_object *objs, int objindex)
{
  int		i;
  int		j;
  int		infos[16];

  j = 0;
  i = 0;
  while (buffer[i])
    {
      while (buffer[i] && !(buffer[i] >= '0'
			    && buffer[i] <= '9') && buffer[i] != '-')
	i++;
      if (j >= 16)
	return (1);
      if (buffer[i])
	{
	  infos[j] = my_getnbr(buffer + i);
	  i += my_nbrlen(infos[j]);
	  j++;
	}
    }
  if (j != 16)
    return (1);
  return (my_fill_objectinfos(infos, objindex, objs));
}

int	my_fill_objectarray(t_object *objects, int size, int fd)
{
  int	i;
  char	*buffer;

  i = 0;
  while (i < size)
    {
      if ((buffer = get_next_line(fd)) != NULL)
	{
	  if (my_parse_objectline(buffer, objects, i))
	    return (1);
	  free(buffer);
	  i++;
	}
      else
	return (1);
    }
  objects[size].type = 0;
  return (0);
}

t_object	*my_create_objects(char *file)
{
  t_object	*objects;
  int		fd;
  char		*buffer;
  int		size;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (NULL);
  if ((buffer = get_next_line(fd)) == NULL)
    return (NULL);
  size = my_getnbr(buffer);
  free(buffer);
  if (size <= 0 || size > 20)
    return (NULL);
  if ((objects = malloc(sizeof(t_object) * (size + 1))) == NULL)
    return (NULL);
  if (my_fill_objectarray(objects, size, fd))
    return (NULL);
  return (objects);
}
