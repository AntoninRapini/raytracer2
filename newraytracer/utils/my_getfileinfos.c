/*
** my_getfileinfos.c for wireframe in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/wireframe/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Dec  3 20:21:08 2016 Antonin Rapini
** Last update Tue Dec 20 18:35:32 2016 Antonin Rapini
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "sources.h"
#include "my_game.h"
#include "utils.h"

int	my_get_linecount(int fd, int *total)
{
  int	size;
  int	lines;
  char	buffer[1024];
  int	i;

  lines = 0;
  size = 1;
  while (size > 0)
    {
      i = 0;
      size = read(fd, buffer, 1023);
      buffer[size] = '\0';
      while (buffer[i])
	{
	  (*total)++;
	  if (buffer[i] == '\n')
	    lines++;
	  i++;
	}
    }
  return (lines);
}

t_game	*my_getfileinfos(char *file)
{
  int	fd;
  int	lines;
  int	total;

  total = 0;
  if ((fd = open(file, O_RDONLY)) == -1)
    return (NULL);
  lines = my_get_linecount(fd, &total);
  close(fd);
  if (lines == 0)
    return (NULL);
  return (my_file_togame(lines, file, total));
}
