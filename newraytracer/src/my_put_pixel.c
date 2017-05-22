/*
** my_put_pixel.c for my_put_pixel in /home/antonin.rapini/GraphicalProgramming/BootstrapIntroduction/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Nov 10 09:55:16 2016 Antonin Rapini
** Last update Wed Mar  8 17:18:40 2017 Antonin Rapini
*/

#include "utils.h"

void	my_put_pixel
(t_my_framebuffer *framebuffer, int x, int y, sfColor color)
{
  if (x >= 0 && x <= framebuffer->width && y >= 0 && y <= framebuffer->height)
    {
      framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
    }
}
