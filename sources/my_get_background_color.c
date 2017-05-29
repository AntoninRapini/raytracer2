/*
** my_get_background_color.c for raytracer2 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer2/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun May 28 21:46:55 2017 Antonin Rapini
** Last update Sun May 28 23:21:57 2017 Antonin Rapini
*/

#include <SFML/Graphics.h>

sfColor		my_get_background_color()
{
  sfColor       background;

  background.r = 20;
  background.g = 40;
  background.b = 200;
  background.a = 255;
  return (background);
}
