/*
** my_scene_utils.c for  in /home/romain.pillot/projects/raytracer2
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun May 28 20:26:03 2017 romain pillot
** Last update Thu Jun  1 04:17:06 2017 Antonin Rapini
*/

#include "utils.h"
#include "sources.h"
#include <stdlib.h>

void *my_free_scene(t_scene *scene, t_config *config)
{
  if (config)
    config_destroy(config);
  if (scene)
    {
      my_free_objects(scene->objects);
      my_free_lights(scene->lights);
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
  scene->eye_pos = my_create_sfvector3f(0, 0, 0);
  scene->eye_rot = my_create_sfvector3f(0, 0, 0);
  scene->screen_size.x = 0;
  scene->screen_size.y = 0;
  scene->objects = NULL;
  scene->lights = NULL;
  scene->background = create_color(0, 0, 0);
  scene->window = NULL;
  scene->screen = NULL;
  scene->refresh = true;
  scene->running = true;
  scene->key_pressed = -1;
  scene->i_object = -1;
  return (scene);
}

void load_scene_infos(t_scene *scene, t_config *config)
{
  scene->eye_pos =
    my_create_sfvector3f(
			 get_integer(config, "properties.eye.position.x"),
			 get_integer(config, "properties.eye.position.y"),
			 get_integer(config, "properties.eye.position.z"));
  scene->eye_rot =
    my_create_sfvector3f(
			 get_integer(config, "properties.eye.rotation.x"),
			 get_integer(config, "properties.eye.rotation.y"),
			 get_integer(config, "properties.eye.rotation.z"));
  scene->screen_size.x = get_integer(config, "properties.screen.width");
  scene->screen_size.y = get_integer(config, "properties.screen.height");
  scene->background =
    create_color(get_integer(config, "properties.background.r"),
		 get_integer(config, "properties.background.g"),
		 get_integer(config, "properties.background.b"));
}

t_scene		*my_create_scene(char *file)
{
  t_scene	*scene;
  t_config	*config;

  if ((scene = my_init_scene()) == NULL ||
      !(config = config_load(file)))
    return (NULL);
  load_scene_infos(scene, config);
  if ((scene->objects = my_create_objects(config)) == NULL)
    return (my_free_scene(scene, config));
  if ((scene->lights = my_create_lights(config)) == NULL)
    return (my_free_scene(scene, config));
  if (my_loadtextures(scene->objects))
    return (my_free_scene(scene, config));
  config_destroy(config);
  return (scene);
}
