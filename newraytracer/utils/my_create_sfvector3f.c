/*
** my_create_vector3.c for raytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Mar  7 19:15:00 2017 Antonin Rapini
** Last update Wed Mar  8 16:34:48 2017 Antonin Rapini
*/

#include <SFML/Graphics.h>

sfVector3f	my_create_sfvector3f(float x, float y, float z)
{
  sfVector3f    vector3;

  vector3.x = x;
  vector3.y = y;
  vector3.z = z;
  return (vector3);
}
