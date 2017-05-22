/*
** my_handlekeypress.c for wireframe in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/wireframe/bonus/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Dec  8 19:25:44 2016 Antonin Rapini
** Last update Wed Mar  8 17:19:01 2017 Antonin Rapini
*/

#include "utils.h"
#include "sources.h"

void	my_handlekeypress
(t_my_framebuffer *framebuffer, t_matrix *matrix, sfEvent event)
{
  my_clear_screen(framebuffer);
  switch (event.key.code)
    {
    case sfKeyNum1 :
      matrix->mode = 0;
      break;
    case sfKeyNum2 :
      matrix->mode = 1;
      break;
    }
}
