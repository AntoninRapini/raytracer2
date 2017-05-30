/*
** my_scene_utils.c for  in /home/romain.pillot/projects/raytracer2
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun May 28 20:26:03 2017 romain pillot
** Last update Tue May 30 18:56:54 2017 Antonin Rapini
*/

#include "utils.h"
#include "sources.h"
#include <stdlib.h>
#include <stdio.h>

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
  scene->refresh = true;
  scene->running = true;
  scene->key_pressed = -1;
  scene->i_object = -1;
  return (scene);
}

int load_scene_infos(t_scene *scene, t_config *config)
{
  scene->eye_pos =
    my_create_sfvector3f(
			 get_integer(config, "properties.eye.position.x"),
			 get_integer(config, "properties.eye.position.y"),
			 get_integer(config, "properties.eye.position.z"));
  scene->screen_size.x = get_integer(config, "properties.screen.width");
  scene->screen_size.y = get_integer(config, "properties.screen.height");
  scene->backgroundtype = get_integer(config,
				      "properties.screen.backgroundtype");
  if (scene->backgroundtype == 2)
    {
      if ((scene->background = my_readbmp
	   (get_string(config,
		       "properties.screen.backgroundfile"))) == NULL)
	return (1);
    }
  return (0);
}

t_scene		*my_create_scene(char *file)
{
  t_scene	*scene;
  t_config	*config;

  if ((scene = my_init_scene()) == NULL ||
      !(config = config_load(file)))
    return (NULL);
  if (load_scene_infos(scene, config))
    return (my_free_scene(scene));
  if ((scene->objects = my_create_objects(config)) == NULL)
    return (my_free_scene(scene));
  if ((scene->lights = my_create_lights(config)) == NULL)
    return (my_free_scene(scene));
  if (my_loadtextures(scene->objects))
    return (my_free_scene(scene));
  config_destroy(config);
  return (scene);
}
