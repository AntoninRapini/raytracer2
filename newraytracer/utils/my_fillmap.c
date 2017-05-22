/*
** my_file_tomatrix.c for wireframe in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/wireframe/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Dec  3 20:14:52 2016 Antonin Rapini
** Last update Tue Jan  3 18:44:15 2017 Antonin Rapini
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_game.h"
#include "utils.h"

int	my_create_line(t_game *game, int j, int i)
{
  if ((game->map.map[j] = malloc(sizeof(int) * (i + 1))) == NULL)
    return (1);
  game->map.map[j][i] = -1;
  return (0);
}

int	my_fillmap(char *file, t_game *game)
{
  char	*old_i;
  int	i;
  int	j;

  j = 0;
  old_i = file;
  while (file[i])
    {
      if (file[i] == '\n')
	{
	  file[i] = '\0';
	  file += i + 1;
	  if ((my_create_line(game, j, i)))
	    return (1);
	  i = 0;
	  while (old_i[i++])
	    game->map.map[j][i - 1] = old_i[i - 1] - 48;
	  j++;
	  i = 0;
	  old_i = file;
	}
      else
	i++;
    }
  return (0);
}
