/*
** my_clear_screen.c for wireframe in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/wireframe/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Dec  8 14:47:48 2016 Antonin Rapini
** Last update Thu Dec  8 14:59:50 2016 Antonin Rapini
*/

#include "utils.h"

void	my_clear_screen(t_my_framebuffer *bfr)
{
  int	i;

  i = 0;
  while (i++ < bfr->width * bfr->height * 4)
    bfr->pixels[i - 1] = 0;
}
