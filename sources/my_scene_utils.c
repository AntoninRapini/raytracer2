/*
** my_scene_utils.c for  in /home/romain.pillot/projects/raytracer2
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun May 28 20:26:03 2017 romain pillot
** Last update Sun May 28 20:26:17 2017 romain pillot
*/

#include "utils.h"
#include "sources.h"
#include <stdlib.h>

t_light         *my_create_lights()
{
  t_light       *lights;

  if ((lights = malloc(sizeof(t_light) * 3)) == NULL)
    return (NULL);
  lights[0] = my_create_light(sfWhite,
			      my_create_sfvector3f(0.8f, 0.8f, 0.5f),
			      my_create_sfvector3f(-200, 0, 100));
  lights[1] = my_create_light(sfBlue,
			      my_create_sfvector3f(0.8f, 0.5f, 0.5f),
			      my_create_sfvector3f(-20, -150, 200));
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
  scene->refresh = true;
  scene->running = true;
  scene->key_pressed = -1;
  scene->i_object = -1;
  return (scene);
}

t_scene		*my_create_scene(char *file)
{
  t_scene	*scene;
  t_config	*config;

  if ((scene = my_init_scene()) == NULL ||
      !(config = config_load(file)))
    return (NULL);
  scene->eye_pos = my_create_sfvector3f(
					get_integer(config, "properties.eye.position.x"),
					get_integer(config, "properties.eye.position.y"),
					get_integer(config, "properties.eye.position.z"));
  scene->screen_size.x = get_integer(config, "properties.screen.width");
  scene->screen_size.y = get_integer(config, "properties.screen.height");
  if ((scene->objects = my_create_objects(config)) == NULL)
    return (my_free_scene(scene));
  config_destroy(config);
  if ((scene->lights = my_create_lights()) == NULL)
    return (my_free_scene(scene));
  return (scene);
}
