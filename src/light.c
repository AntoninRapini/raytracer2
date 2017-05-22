/*
** light.c for raytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1/src
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Mar  7 18:05:03 2017 Antonin Rapini
** Last update Mon Mar 20 23:52:38 2017 Antonin Rapini
*/

#include <math.h>
#include <SFML/Graphics.h>
#include <stdio.h>

float	get_light_coef(sfVector3f light, sfVector3f normal)
{
  float coef;
  float	normal_norm;
  float light_norm;
  sfVector3f newlight;
  sfVector3f newnormal;

  coef = 0;
  normal_norm = sqrt(pow(normal.x, 2) + pow(normal.y, 2) + pow(normal.z, 2));
  light_norm = sqrt(pow(light.x, 2) + pow(light.y, 2) + pow(light.z, 2));
  if (normal_norm != 0 && light_norm != 0)
    {
      newnormal.x = normal.x / normal_norm;
      newnormal.y = normal.y / normal_norm;
      newnormal.z = normal.z / normal_norm;
      newlight.x = light.x / light_norm;
      newlight.y = light.y / light_norm;
      newlight.z = light.z / light_norm;
      coef = newnormal.x * newlight.x + newnormal.y * newlight.y + newnormal.z * newlight.z;
    }
  return (coef);
}
