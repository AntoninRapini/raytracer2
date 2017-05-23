/*
** light.c for raytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1/src
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Mar  7 18:05:03 2017 Antonin Rapini
** Last update Wed May 24 00:57:15 2017 Antonin Rapini
*/

#include <math.h>
#include <SFML/Graphics.h>
#include <stdio.h>

float		get_light_coef(sfVector3f light, sfVector3f normal)
{
  float		coef;
  float		normal_norm;
  float		light_norm;

  coef = 0;
  normal_norm = sqrt(pow(normal.x, 2) + pow(normal.y, 2) + pow(normal.z, 2));
  light_norm = sqrt(pow(light.x, 2) + pow(light.y, 2) + pow(light.z, 2));
  if (normal_norm != 0 && light_norm != 0)
    {
      light.x = light.x / light_norm;
      light.y = light.y / light_norm;
      light.z = light.z / light_norm;
      normal.x = normal.x / normal_norm;
      normal.y = normal.y / normal_norm;
      normal.z = normal.z / normal_norm;
      coef = (light.x * normal.x) + (light.y * normal.y) + (light.z * normal.z);
    }
  return (coef);
}
