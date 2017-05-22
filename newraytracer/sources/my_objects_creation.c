/*
** my_objects_creation.c for raytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Mar  7 22:45:58 2017 Antonin Rapini
** Last update Sun Mar 19 19:18:51 2017 Antonin Rapini
*/

#include <SFML/Graphics.h>
#include "my_light.h"
#include "utils.h"
#include "my_object.h"

t_object	my_create_sphere(int radius, sfColor color)
{
  t_object	sphere;

  sphere.position = my_create_sfvector3f(0, 0, 0);
  sphere.rotation = my_create_sfvector3f(0, 0, 0);
  sphere.color = color;
  sphere.type = 2;
  sphere.info = radius;
  sphere.brillance = 1;
  return (sphere);
}

t_object	my_create_plane(sfColor color)
{
  t_object	plane;

  plane.position = my_create_sfvector3f(0, 0, 0);
  plane.rotation = my_create_sfvector3f(0, 0, 0);
  plane.color = color;
  plane.type = 1;
  plane.info = 0;
  plane.brillance = 1;
  return (plane);
}

t_light		my_create_light(sfColor color, int brightness, sfVector3f pos)
{
  t_light	light;

  light.position = pos;
  light.rotation = my_create_sfvector3f(0, 0, 0);
  light.color = color;
  light.brightness = brightness;
  return (light);
}
