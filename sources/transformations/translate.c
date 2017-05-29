/*
** my_translation.c for wireframe in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/wireframe/transformations
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Dec  8 14:33:43 2016 Antonin Rapini
** Last update Sat Feb 25 16:29:07 2017 Antonin Rapini
*/

#include  <SFML/Graphics.h>

sfVector3f translate(sfVector3f to_translate, sfVector3f translations)
{
  to_translate.x += translations.x;
  to_translate.y += translations.y;
  to_translate.z += translations.z;
  return (to_translate);
}
