/*
** my_create_game.c for wolf3d in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/wolf3d/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Dec 21 16:49:09 2016 Antonin Rapini
** Last update Thu Dec 22 19:07:59 2016 Antonin Rapini
*/

#include <stdlib.h>
#include "my_game.h"

t_game		*my_create_game()
{
  t_game	*game;

  if ((game = malloc(sizeof(t_game))) == NULL)
    return (NULL);
  game->player.pos.x = 0;
  game->player.pos.y = 0;
  game->map.size.x = 0;
  game->map.size.y = 0;
  game->plane.x = 0;
  game->plane.y = 0.66;
  game->player.dir.x = -1;
  game->player.dir.y = 0;
  return (game);
}
