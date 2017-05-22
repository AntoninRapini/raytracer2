/*
** my_draw_line.c for my_draw_line in /home/antonin.rapini/GraphicalProgramming/bswireframe/src
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Nov 14 10:53:51 2016 Antonin Rapini
** Last update Sat Dec 10 16:12:31 2016 Antonin Rapini
*/

#include "utils.h"

void	swap(sfVector2i **a, sfVector2i **b)
{
  sfVector2i *tmp;

  tmp = (*b);
  (*b) = (*a);
  (*a) = tmp;
}

void	my_draw_xslope
(t_my_framebuffer *frame, sfVector2i *from, sfVector2i *to, sfColor color)
{
  float y;
  float y_offset;
  int	x;

  if (to->x < from->x)
    swap(&from, &to);
  y_offset = (float)(to->y - from->y) / (float)(to->x - from->x);
  y = from->y;
  x = from->x;
  while (x++ <= to->x)
    {
      if (x - 1 >= 0 && x - 1 <= frame->width
	  && y >= 0 && y <= frame->height)
	my_put_pixel(frame, x - 1, y, color);
      y += y_offset;
    }
}

void	my_draw_yslope
(t_my_framebuffer *frame, sfVector2i *from, sfVector2i *to, sfColor color)
{
  int	 y;
  float x_offset;
  float	x;

  if (to->y < from->y)
    swap(&from, &to);
  x_offset = (float)(to->x - from->x) / (float)(to->y - from->y);
  y = from->y;
  x = from->x;
  while (y++ <= to->y)
    {
      if (x >= 0 && x <= frame->width
	  && y - 1 >= 0 && y - 1<= frame->height)
	my_put_pixel(frame, x, y - 1, color);
      x += x_offset;
    }
}

void	my_draw_line
(t_my_framebuffer *frame, sfVector2i from, sfVector2i to, sfColor color)
{
  int	x_dist;
  int	y_dist;

  x_dist = to.x - from.x > 0 ? to.x - from.x : -(to.x - from.x);
  y_dist = to.y - from.y > 0 ? to.y - from.y : -(to.y - from.y);
  if (x_dist > y_dist)
    my_draw_xslope(frame, &from, &to, color);
  else
    my_draw_yslope(frame, &from, &to, color);
}

