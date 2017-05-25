/*
** my_color_utils.c for raytracer2 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer2/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu May 25 17:41:28 2017 Antonin Rapini
** Last update Thu May 25 17:59:28 2017 Antonin Rapini
*/

#include <SFML/Graphics.h>

sfColor my_mul_color(sfColor color, float coeff)
{
  color.r = color.r * coeff;
  color.g = color.g * coeff;
  color.b = color.b * coeff;
  return (color);
}

sfColor my_add_colors(sfColor color, sfColor add)
{
  if ((int)color.r + (int)add.r > 255)
    color.r = 255;
  else
    color.r = color.r + add.r;
  if ((int)color.g + (int)add.g > 255)
    color.g = 255;
  else
    color.g = color.g + add.g;
  if ((int)color.b + (int)add.b > 255)
    color.b = 255;
  else
    color.b = color.b + add.b;
  return (color);
}
