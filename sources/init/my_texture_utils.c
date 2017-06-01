/*
** my_texture_utils.c for raytracer2 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer2/sources/init
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed May 31 23:22:03 2017 Antonin Rapini
** Last update Wed May 31 23:29:58 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "sources.h"

void	*my_free_texture(t_texture *texture)
{
  int	i;

  i = 0;
  if (texture)
    {
      if (texture->colors)
	{
	  while (texture->colors[i])
	    {
	      free(texture->colors[i]);
	      i++;
	    }
	  free(texture->colors);
	}
      free(texture);
    }
  return (NULL);
}

t_texture	*my_init_texture()
{
  t_texture	*texture;

  if ((texture = malloc(sizeof(t_texture))) == NULL)
    return (NULL);
  texture->colors = 0;
  texture->size.x = 0;
  texture->size.y = 0;
  return (texture);
}
