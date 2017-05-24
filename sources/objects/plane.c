/*
** intersect_plane.c for bsraytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/bsraytracer1/src
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb  8 15:47:59 2017 Antonin Rapini
** Last update Wed May 24 22:26:30 2017 Antonin Rapini
*/

#include <SFML/Graphics.h>
#include "my_object.h"

float intersect_plane(t_object *obj, sfVector3f eye_pos, sfVector3f dir_vector)
{
  if (obj)
    {
    }
  if (dir_vector.z != 0 && -eye_pos.z / dir_vector.z > 0)
    return (-eye_pos.z / dir_vector.z);
  return (-1);
}

sfVector3f get_normal_plane(t_object *obj, sfVector3f ip)
{
  ip.x = 0;
  ip.y = 0;
  ip.z = 100 * obj->info == 0 ? -1 : 1;
  return (ip);
}
