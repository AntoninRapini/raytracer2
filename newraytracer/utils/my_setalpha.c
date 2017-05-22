/*
** my_put_redpixel.c for bswireframe_tests in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/bswireframe_tests/src
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Dec  6 22:13:38 2016 Antonin Rapini
** Last update Wed Dec  7 14:58:10 2016 Antonin Rapini
*/

#include "utils.h"

sfColor		my_setalpha(sfColor color, float alpha)
{
  sfColor	my_color;

  my_color.r = color.r;
  my_color.g = color.g;
  my_color.b = color.b;
  my_color.a = (int)(alpha * color.a);
  return (my_color);
}
