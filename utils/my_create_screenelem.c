/*
** my_create_screenelem.c for wolf3d in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/wolf3dbonus/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Dec 26 19:03:41 2016 Antonin Rapini
** Last update Wed Mar  8 17:15:59 2017 Antonin Rapini
*/

#include "utils.h"
#include "my_screenelement.h"
#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

t_screenelem		*my_create_screenelem(int width, int height)
{
  t_screenelem		*screenelem;
  sfSprite		*sprite;
  sfTexture		*texture;
  t_my_framebuffer	*framebuffer;

  if ((screenelem = malloc(sizeof(t_screenelem))) == NULL)
    return (NULL);
  sprite = sfSprite_create();
  framebuffer = my_framebuffer_create(width, height);
  texture = sfTexture_create(width, height);
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfTexture_updateFromPixels(texture,
			     framebuffer->pixels, width, height, 0, 0);
  screenelem->sprite = sprite;
  screenelem->texture = texture;
  screenelem->frb = framebuffer;
  return (screenelem);
}
