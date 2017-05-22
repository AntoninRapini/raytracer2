/*
** my_file_tomatrix.c for wireframe in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/wireframe/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Dec  3 20:14:52 2016 Antonin Rapini
** Last update Tue Jan  3 18:44:40 2017 Antonin Rapini
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "utils.h"
#include "my_game.h"
#include "sources.h"

int	my_getplayerpos(t_game *game)
{
  int	i;
  int	j;

  i = 0;
  while (i < game->map.size.y)
    {
      j = 0;
      while (game->map.map[i][j] != -1)
	{
	  if (game->map.map[i][j] == 2)
	    {
	      game->player.pos.x = j;
	      game->player.pos.y = i;
	      return (0);
	    }
	  j++;
	}
      i++;
    }
  return (1);
}

t_game		*my_file_togame(int lines, char *filename, int filesize)
{
  int		fd;
  t_game	*game;
  char		*buffer;

  if ((buffer = malloc(sizeof(char) * filesize + 1)) == NULL)
    return (NULL);
  if ((game = my_create_game()) == NULL)
    return (NULL);
  if ((game->map.map = malloc(sizeof(int *) * lines)) == NULL)
    return (NULL);
  fd = open(filename, O_RDONLY);
  read(fd, buffer, filesize);
  buffer[filesize] = '\0';
  game->map.size.y= lines;
  if ((my_fillmap(buffer, game)))
    return (NULL);
  if ((my_getplayerpos(game)))
    return (NULL);
  return (game);
}
