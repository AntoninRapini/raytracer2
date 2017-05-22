/*
** my_screenelement.h for wolf3d in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/wolf3dbonus/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Dec 26 18:59:17 2016 Antonin Rapini
** Last update Mon Dec 26 19:20:25 2016 Antonin Rapini
*/

#ifndef MY_SCREENELEMENT_H_
# define MY_SCREENELEMENT_H_

#include "my_framebuffer.h"
#include <SFML/Graphics/RenderWindow.h>

typedef struct		s_screenelem
{
  sfSprite		*sprite;
  sfTexture		*texture;
  t_my_framebuffer	*frb;
}			t_screenelem;

#endif /* !MY_SCREENELEMENT_H_ */
