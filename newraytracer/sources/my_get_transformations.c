/*
** my_transformobject.c for wireframe in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/wireframebonus/transformations
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Dec  9 18:37:07 2016 Antonin Rapini
** Last update Sun Mar 19 21:33:52 2017 Antonin Rapini
*/

#include "sources.h"

void		my_get_transformations(t_scene *scene)
{
  sfVector3f	translation;

  translation.x = (sfKeyboard_isKeyPressed(sfKeyUp) - sfKeyboard_isKeyPressed(sfKeyDown)) * 5;
  translation.y	= (sfKeyboard_isKeyPressed(sfKeyLeft) - sfKeyboard_isKeyPressed(sfKeyRight)) * 5;
  translation.z = (sfKeyboard_isKeyPressed(sfKeyZ) - sfKeyboard_isKeyPressed(sfKeyS)) * 5;
  scene->eye_pos = translate(scene->eye_pos, translation);
}
