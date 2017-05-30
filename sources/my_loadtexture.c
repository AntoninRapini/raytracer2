/*
** my_readbmp.c for wolf3d in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/wolf3dbonus/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Dec 29 16:32:40 2016 Antonin Rapini
** Last update Tue May 30 20:50:24 2017 Antonin Rapini
*/

#include <unistd.h>
#include <fcntl.h>
#include "my_object.h"
#include <stdlib.h>
#include "utils.h"
#include <stdio.h>
#include <math.h>

int		fill_bmpheader(t_bmpheader *header, int fd)
{
  int		size;

  size = read(fd, (char *)header, sizeof(t_bmpheader));
  if (size != sizeof(t_bmpheader))
    return (1);
  return (0);
}

sfColor		**create_texture(unsigned char *texture, int sizex, int sizey)
{
  sfColor	**colors;
  int		y;
  int		x;
  int		i;

  y = i = 0;
  if ((colors = malloc(sizeof(sfColor *) * sizey)) == NULL)
    return (NULL);
  while (i++ < sizey)
    if ((colors[i - 1] = malloc(sizeof(sfColor) * sizex)) == NULL)
      return (NULL);
  i = 0;
  while (y++ < sizey)
    {
      x = 0;
      while (x++ < sizex && i + 2 < (sizex * sizey) * 3)
	{
	  colors[y - 1][x - 1].b = texture[i];
	  colors[y - 1][x - 1].g = texture[i + 1];
	  colors[y - 1][x - 1].r = texture[i + 2];
	  colors[y - 1][x - 1].a = 255;
	  i += 3;
	}
    }
  return (colors);
}

int fill_texturesize(t_bmpheader *header, t_texture *texture)
{
  texture->size.x = (header->imagewidth[3] << 24)
    | (header->imagewidth[2] << 16)
    | (header->imagewidth[1] << 8) | header->imagewidth[0];
  texture->size.y = (header->imageheight[3] << 24)
    | (header->imageheight[2] << 16)
    | (header->imageheight[1] << 8) | header->imageheight[0];
  return (texture->size.x * texture->size.y);
}

t_texture 	*my_readbmp(char *filename)
{
  t_bmpheader	header;
  int		fd;
  int		fullsize;
  int		read_size;
  unsigned char	*buffer;
  t_texture	*texture;

  if ((fd = open(filename, O_RDONLY)) != -1)
    {
      if (fill_bmpheader(&header, fd)
	  || (texture = malloc(sizeof(t_texture))) == NULL)
	return (NULL);
      fullsize = fill_texturesize(&header, texture);
      if ((buffer = malloc(sizeof(unsigned char)
			   * ((fullsize * 3)+ 1))) == NULL)
	return (NULL);
      if ((read_size = read(fd, buffer, fullsize * 3)) != fullsize * 3)
	return (NULL);
      if ((texture->colors = create_texture
	   (buffer, texture->size.x, texture->size.y)) == NULL)
	return (NULL);
      free(buffer);
      return (texture);
    }
  return (NULL);
}

int		my_loadtextures(t_object **objs)
{
  int		i;

  i = 0;
  while (objs[i])
    {
      if (objs[i]->materialtype == 2)
	{
	  if ((objs[i]->diffuse_map =
	       my_readbmp(objs[i]->diffuse_map_filename)) == NULL)
	    return (1);
	}
      i++;
    }
  return (0);
}
