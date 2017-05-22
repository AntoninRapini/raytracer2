/*
** translate.c for raytracer in /home/hartwoom/Epitech/Infographie/raytracer1/src
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Tue Mar  7 16:56:47 2017 HartWoom
** Last update Thu Mar 16 14:35:16 2017 HartWoom
*/

#include "my.h"

sfVector3f	translate(sfVector3f to_translate, sfVector3f translations)
{
  sfVector3f	new_translate;

  new_translate.x = to_translate.x + translations.x;
  new_translate.y = to_translate.y + translations.y;
  new_translate.z = to_translate.z + translations.z;
  return (new_translate);
}
