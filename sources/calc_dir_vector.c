/*
** calc_dir_vector.c for bsraytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/bsraytracer1/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb  8 15:03:55 2017 Antonin Rapini
** Last update Wed Mar  8 17:18:09 2017 Antonin Rapini
*/

#include <SFML/Graphics.h>

sfVector3f calc_dir_vector
(float dist_to_plane, sfVector2i screen_size, sfVector2i screen_pos)
{
  sfVector3f dir_vector;

  dir_vector.x = dist_to_plane;
  dir_vector.y = (screen_size.x / 2) - screen_pos.x;
  dir_vector.z = (screen_size.y / 2) - screen_pos.y;
  return (dir_vector);
}
