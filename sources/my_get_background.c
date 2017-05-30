/*
** my_get_background_color.c for raytracer2 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer2/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun May 28 21:46:55 2017 Antonin Rapini
** Last update Tue May 30 18:55:44 2017 Antonin Rapini
*/

#include <SFML/Graphics.h>

sfColor		my_get_background()
{
  sfColor       background;

  background.r = 120;
  background.g = 140;
  background.b = 180;
  background.a = 255;
  return (background);
}
