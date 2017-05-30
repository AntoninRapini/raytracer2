/*
** my_create_screenelem.c for wolf3d in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/wolf3dbonus/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Dec 26 19:03:41 2016 Antonin Rapini
** Last update Tue May 23 04:21:25 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "utils.h"
#include "sources.h"

void *my_free_screenelem(t_screenelem *screenelem)
{
  if (screenelem)
    {
      if (screenelem->sprite)
	sfSprite_destroy(screenelem->sprite);
      if (screenelem->texture)
	sfTexture_destroy(screenelem->texture);
      if (screenelem->frb)
	my_free_framebuffer(screenelem->frb);
      free(screenelem);
    }
  return (NULL);
}

t_screenelem		*my_init_screenelem()
{
  t_screenelem		*screenelem;

  if ((screenelem = malloc(sizeof(t_screenelem))) == NULL)
    return (NULL);
  screenelem->sprite = NULL;
  screenelem->texture = NULL;
  screenelem->frb = NULL;
  return (screenelem);
}

t_screenelem		*my_create_screenelem(int width, int height)
{
  t_screenelem		*screenelem;

  if ((screenelem = my_init_screenelem()) == NULL)
    return (NULL);
  if ((screenelem->sprite = sfSprite_create()) == NULL)
    return (my_free_screenelem(screenelem));
  if ((screenelem->texture = sfTexture_create(width, height)) == NULL)
    return (my_free_screenelem(screenelem));
  if ((screenelem->frb = my_create_framebuffer(width, height)) == NULL)
    return (my_free_screenelem(screenelem));
  sfSprite_setTexture(screenelem->sprite, screenelem->texture, sfTrue);
  return (screenelem);
}
