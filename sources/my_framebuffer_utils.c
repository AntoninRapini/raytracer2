/*
** my_framebuffer_create.c for my_framebuffer_create in /home/antonin.rapini/GraphicalProgramming/BootstrapIntroduction/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Nov 10 09:35:22 2016 Antonin Rapini
** Last update Tue May 23 04:38:00 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "utils.h"

void *my_free_framebuffer(t_my_framebuffer *framebuffer)
{
  if (framebuffer)
    {
      if (framebuffer->pixels)
	free(framebuffer->pixels);
      free(framebuffer);
    }
  return (NULL);
}

t_my_framebuffer	*my_init_framebuffer()
{
  t_my_framebuffer	*framebuffer;

  if ((framebuffer = malloc(sizeof(t_my_framebuffer))) == NULL)
    return (NULL);
  framebuffer->pixels = NULL;
  framebuffer->width = 0;
  framebuffer->height = 0;
  return (framebuffer);
}

t_my_framebuffer	*my_create_framebuffer(int width, int height)
{
  t_my_framebuffer	*framebuffer;

  if ((framebuffer = my_init_framebuffer()) == NULL)
    return (NULL);
  if ((framebuffer->pixels =
       malloc(width * height * 4 * sizeof(sfUint8))) == NULL)
    return (my_free_framebuffer(framebuffer));
  my_memset(framebuffer->pixels, 0, width * height * 4);
  framebuffer->width = width;
  framebuffer->height = height;
  return (framebuffer);
}
