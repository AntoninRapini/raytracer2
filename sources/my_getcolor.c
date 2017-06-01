/*
** my_draw_objects.c for raytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Mar  7 19:27:50 2017 Antonin Rapini
** Last update Thu Jun  1 03:57:21 2017 Antonin Rapini
*/

#include <SFML/Graphics.h>
#include "sources.h"
#include "utils.h"

sfColor		my_getcolor(t_scene *scene, sfVector3f dir)
{
  t_ray		ray;

  dir = rotate_xyz(dir, scene->eye_rot);
  init_ray(&ray, dir, scene->eye_pos, 0);
  find_intersect(scene->objects, &ray, -1);
  if (ray.distance != -1)
    return (my_process_light(scene, &ray));
  return (scene->background);
}
