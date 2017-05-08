/*
** light.c for raytracer in /home/hartwoom/Epitech/Infographie/raytracer1/src
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Tue Mar  7 17:33:58 2017 HartWoom
** Last update Wed Mar 22 14:27:38 2017 HartWoom
*/

#include "my.h"

float	get_light_coef(sfVector3f light, sfVector3f normal)
{
  float	k;
  float l;
  float n;
  float l_n;

  l = sqrt(powf(light.x, 2) + powf(light.y, 2) + powf(light.z, 2));
  n = sqrt(powf(normal.x, 2) + powf(normal.y, 2) + powf(normal.z, 2));
  k = (light.x * normal.x) + (light.y * normal.y) + (light.z * normal.z);
  if ((l_n = l * n) != 0)
    k = k / l_n;
  if (k >= 0 && k <= 1)
    return (k);
  else if (k > 1)
    return (1);
  else if (k < 0)
    return (0);
  return (0);
}
