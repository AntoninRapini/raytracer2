/*
** my_raytracer_utils.c for raytracer2 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer2/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon May 22 22:02:46 2017 Antonin Rapini
** Last update Thu Jun  1 02:23:16 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "my_raytracer.h"
#include "sources.h"

void *my_free_raytracer(t_raytracer *raytracer)
{
  if (raytracer)
    {
      if (raytracer->window)
	sfRenderWindow_destroy(raytracer->window);
      if (raytracer->scene)
	my_free_scene(raytracer->scene, NULL);
      if (raytracer->screen)
	my_free_screenelem(raytracer->screen);
      free(raytracer);
    }
  return (NULL);
}

t_raytracer	*my_init_raytracer()
{
  t_raytracer	*raytracer;

  if ((raytracer = malloc(sizeof(t_raytracer))) == NULL)
    return (NULL);
  raytracer->window = NULL;
  raytracer->screen = NULL;
  raytracer->scene = NULL;
  return (raytracer);
}

t_raytracer	*my_create_raytracer(char *file)
{
  t_raytracer	*raytracer;

  if ((raytracer = my_init_raytracer()) == NULL)
    return (NULL);
  if ((raytracer->scene = my_create_scene(file)) == NULL)
    return (my_free_raytracer(raytracer));
  if ((raytracer->screen =
       my_create_screenelem(raytracer->scene->screen_size.x,
			    raytracer->scene->screen_size.y)) == NULL)
    return (my_free_raytracer(raytracer));
  if ((raytracer->window = my_create_window
       ("Raytracer 2", raytracer->scene->screen_size.x,
			raytracer->scene->screen_size.y)) == NULL)
    return (my_free_raytracer(raytracer));
  return (raytracer);
}
