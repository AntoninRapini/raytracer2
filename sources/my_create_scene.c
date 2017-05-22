/*
** my_create_scene.c for raytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Mar  7 19:11:19 2017 Antonin Rapini
** Last update Mon May 22 14:51:59 2017 Antonin Rapini
*/

#include "utils.h"
#include "sources.h"
#include <stdlib.h>

t_light		*my_create_lights()
{
  t_light	*lights;

  if ((lights = malloc(sizeof(t_light) * 3)) == NULL)
    return (NULL);
  lights[0] = my_create_light(sfYellow, 1, my_create_sfvector3f(0, 100, 100));
  lights[2].brightness = 0;
  return (lights);
}

t_scene		*my_create_scene(int width, int height)
{
  t_scene	*scene;

  if ((scene = malloc(sizeof(t_scene))) == NULL)
    return (NULL);
  scene->eye_pos = my_create_sfvector3f(-200, 0, 20);
  scene->screen_size.x = width;
  scene->screen_size.y = height;
  if ((scene->objects = my_create_objects()) == NULL)
    return (NULL);
  if ((scene->lights = my_create_lights()) == NULL)
    return (NULL);
  return (scene);
}
