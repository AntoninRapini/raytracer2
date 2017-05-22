/*
** my_vector3_utils.c for raytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Mar 14 22:16:53 2017 Antonin Rapini
** Last update Tue Mar 14 22:18:16 2017 Antonin Rapini
*/

#include <SFML/Graphics.h>

sfVector3f my_add_v3(sfVector3f a, sfVector3f b, int sign)
{
  sfVector3f new;

  new.x = a.x + b.x * sign;
  new.y = a.y + b.y * sign;
  new.z = a.z + b.z * sign;
  return (new);
}
