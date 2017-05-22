/*
** my_framebuffer_create.c for my_framebuffer_create in /home/antonin.rapini/GraphicalProgramming/BootstrapIntroduction/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Nov 10 09:35:22 2016 Antonin Rapini
** Last update Fri Dec  9 14:25:39 2016 Antonin Rapini
*/

#include <stdlib.h>
#include "utils.h"

t_my_framebuffer	*my_framebuffer_create(int width, int height)
{
  int			i;
  t_my_framebuffer	*framebuffer;

  i = 0;
  if ((framebuffer = malloc(sizeof(t_my_framebuffer))) == NULL)
    return (NULL);
  if ((framebuffer->pixels
       = malloc(width * height * 4 * sizeof(sfUint8))) == NULL)
    return (NULL);
  while (i++ < width * height * 4)
    framebuffer->pixels[i - 1] = 0;
  framebuffer->width = width;
  framebuffer->height = height;
  return (framebuffer);
}
