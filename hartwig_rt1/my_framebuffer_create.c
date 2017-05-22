/*
** my_framebuffer_create.c for wireframe in /home/antoine.hartwig/bswireframe
** 
** Made by Antoine Hartwig
** Login   <antoine.hartwig@epitech.net>
** 
** Started on  Tue Dec  6 09:30:36 2016 Antoine Hartwig
** Last update Sun Jan 15 18:43:19 2017 Antoine Hartwig
*/

#include "include/my.h"

t_my_framebuffer	*my_framebuffer_create(int width, int height)
{
  t_my_framebuffer	*element;

  if ((element = malloc(sizeof(t_my_framebuffer))) == NULL)
    return (NULL);
  element->width = width;
  element->height = height;
  if ((element->pixels = malloc(sizeof(sfUint8)
				* (width * height * 4))) == NULL)
    return (NULL);
  return (element);
}
