/*
** calc_vector.c for raytracer in /home/hartwoom/Epitech/Infographie/raytracer1
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Wed Mar 22 10:50:15 2017 HartWoom
** Last update Wed Mar 22 16:38:18 2017 HartWoom
*/

#include "my.h"

sfVector3f	calc_light_v(sfVector3f inter, sfVector3f src)
{
  sfVector3f	light_v;

  light_v.x = src.x - inter.x;
  light_v.y = src.y - inter.y;
  light_v.z = src.z - inter.z;
  return (light_v);
}
