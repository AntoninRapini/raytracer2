/*
** my_commands.c for raytracer2 in /home/raphael.goulmot/rendu/raytracer2
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Wed May 24 15:25:44 2017 Raphaël Goulmot
** Last update Thu Jun  1 10:40:15 2017 Raphaël Goulmot
*/

#include <unistd.h>
#include "sources.h"
#include "utils.h"

static void	move_view(t_scene *scene, int key)
{
  float		*axe;
  int		speed;

  axe = 0;
  speed = key == sfKeyUp || key== sfKeyLeft ? 5 : 0;
  speed = key == sfKeyDown || key == sfKeyRight ? -5 : speed;
  speed = sfKeyA == key ? 5 : sfKeyE == key ? -5 : 0;
  if (speed)
    axe = key == sfKeyUp || key == sfKeyDown
      ? &scene->eye_pos.x : sfKeyA == key || sfKeyE == key
      ? &scene->eye_rot.z : &scene->eye_pos.y;
  if (axe)
    {
      *axe += speed;
      scene->refresh = true;
    }
}

static void	move_object(t_scene *scene, t_object *obj, int key)
{
  float		*axe;
  int		speed;

  axe = 0;
  speed = key == sfKeyZ || key == sfKeyQ ? 5 : 0;
  speed = key == sfKeyS || key == sfKeyD ? -5 : speed;
  speed = key == sfKeySpace ? 5 : key == sfKeyC ? -5 : speed;
  if (speed)
    axe = key == sfKeyZ || key == sfKeyS
      ? &obj->position.x : key == sfKeyQ || key == sfKeyD
      ? &obj->position.y : &obj->position.z;
  if (axe)
    *axe += speed;
  else
    rotate_object(scene, obj, key);
  scene->refresh = true;
}

static void	select_object(t_scene *scene, int key)
{
  t_object	*obj;
  t_object	*old;

  old = 0;
  obj = 0;
  if (scene->i_object > -1)
    old = scene->objects[scene->i_object];
  scene->i_object += sfKeyPageUp == key ? 1 : -1;
  if (scene->i_object < -1)
    scene->i_object = -1;
  else if (scene->i_object > -1
	   && (obj = scene->objects[scene->i_object]))
    {
      obj->old_color = obj->color;
      obj->color = sfWhite;
    }
  else if (scene->i_object != -1)
    scene->i_object += sfKeyPageUp == key ? -1 : 1;
  if (old && (scene->i_object == -1 || (obj && obj->type)))
    old->color = old->old_color;
}

void		commands(t_scene *scene, int key)
{
  t_object	*obj;

  if (scene->key_pressed == -1)
    scene->key_pressed = key;
  else if (scene->key_pressed != key)
    return;
  if (key == sfKeyUp || key == sfKeyDown
      || key == sfKeyLeft || key == sfKeyRight
      || key == sfKeyA || sfKeyE == key)
    move_view(scene, key);
  else if (scene->i_object > -1
	   && (obj = scene->objects[scene->i_object])->type)
    move_object(scene, obj, key);
}

void		commands_off(t_scene *scene, int key)
{
  if (scene->key_pressed == key)
    {
      if (key == sfKeyPageUp || key == sfKeyPageDown)
	select_object(scene, key);
      scene->key_pressed = -1;
      scene->refresh = true;
      my_draw_screen(scene->window, scene->screen, scene);
    }
}
