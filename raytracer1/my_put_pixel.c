/*
** my_put_pixel.c for wireframe in /home/antoine.hartwig/bswireframe
** 
** Made by Antoine Hartwig
** Login   <antoine.hartwig@epitech.net>
** 
** Started on  Tue Dec  6 09:29:24 2016 Antoine Hartwig
** Last update Fri Mar  3 19:51:29 2017 HartWoom
*/

#include "include/my.h"

void	my_put_pixel(t_my_framebuffer* framebuffer,
		     int x, int y, sfColor color)
{
  if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
    {
      framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
    }
}
