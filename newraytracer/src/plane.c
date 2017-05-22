/*
** intersect_plane.c for bsraytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/bsraytracer1/src
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb  8 15:47:59 2017 Antonin Rapini
** Last update Wed Mar 15 17:15:02 2017 Antonin Rapini
*/

#include <SFML/Graphics.h>

float intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector)
{
  if (dir_vector.z != 0 && -eye_pos.z / dir_vector.z > 0)
    return (-eye_pos.z / dir_vector.z);
  return (-1);
}

sfVector3f	get_normal_plane(int upward)
{
  sfVector3f	normal;

  normal.x = 0;
  normal.y = 0;
  normal.z = 100 * upward == 0 ? -1 : 1;
  return (normal);
}
