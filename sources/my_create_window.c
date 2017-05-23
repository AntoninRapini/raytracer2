/*
** bootstrap_intro.c for bootstrap_intro in /home/antonin.rapini/GraphicalProgramming/BootstrapIntroduction
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Nov 10 09:28:15 2016 Antonin Rapini
** Last update Mon May 22 23:25:24 2017 Antonin Rapini
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>

sfRenderWindow		*my_create_window(char *name, int width, int height)
{
  sfRenderWindow	*window;
  sfVideoMode		mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (window == NULL)
    return (NULL);
  return (window);
}
