/*
** my_create_scene.c for raytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Mar  7 19:11:19 2017 Antonin Rapini
** Last update Tue May 23 22:52:57 2017 Antonin Rapini
*/

#include "utils.h"
#include "sources.h"
#include <stdlib.h>

t_light		*my_create_lights()
{
  t_light	*lights;

  if ((lights = malloc(sizeof(t_light) * 2)) == NULL)
    return (NULL);
  lights[0] = my_create_light(sfYellow, 1, my_create_sfvector3f(0, 0, 200));
  lights[1].brightness = 0;
  return (lights);
}

void *my_free_scene(t_scene *scene)
{
  if (scene)
    {
      if (scene->objects)
	free(scene->objects);
      if (scene->lights)
	free(scene->lights);
      free(scene);
    }
  return (NULL);
}

t_scene		*my_init_scene()
{
  t_scene	*scene;

  if ((scene = malloc(sizeof(t_scene))) == NULL)
    return (NULL);
  scene->eye_pos.x = 0;
  scene->eye_pos.y = 0;
  scene->eye_pos.z = 0;
  scene->screen_size.x = 0;
  scene->screen_size.y = 0;
  scene->objects = 0;
  scene->lights = 0;
  return (scene);
}

t_scene		*my_create_scene(char *file)
{
  t_scene	*scene;

  if ((scene = my_init_scene()) == NULL)
    return (NULL);
  scene->eye_pos = my_create_sfvector3f(-200, 0, 20);
  scene->screen_size.x = 1280;
  scene->screen_size.y = 720;
  if ((scene->objects = my_create_objects(file)) == NULL)
    return (my_free_scene(scene));
  if ((scene->lights = my_create_lights()) == NULL)
    return (my_free_scene(scene));
  return (scene);
}
