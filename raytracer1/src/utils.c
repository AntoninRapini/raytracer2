/*
** utils.c for raytracer in /home/hartwoom/Epitech/Infographie/raytracer1
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Tue Mar  7 19:06:47 2017 HartWoom
** Last update Thu Mar 16 14:35:01 2017 HartWoom
*/

#include "my.h"

float   case_1(float a, float b, float delta)
{
  float k1;
  float k2;

  if (a == 0)
    return (0);
  k1 = (-b + sqrt(delta)) / (2 * a);
  k2 = (-b - sqrt(delta)) / (2 * a);
  if (k1 <= k2 && k1 > 0)
    return (k1);
  else if (k2 < k1 && k2 > 0)
    return (k2);
  else if (k1 >= k2 && k2 < 0 && k1 > 0)
    return (k1);
  else if (k2 > k1 && k2 > 0 && k1 < 0)
    return (k2);
  return (-1);
}

float   case_2(float a, float b)
{
  float k1;

  if (a == 0)
    return (0);
  k1 = -b / (2 * a);
  if (k1 > 0)
    return (k1);
  return (-1);
}
