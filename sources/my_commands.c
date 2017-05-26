/*
** my_commands.c for raytracer2 in /home/raphael.goulmot/rendu/raytracer2
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Wed May 24 15:25:44 2017 Raphaël Goulmot
** Last update Fri May 26 16:55:18 2017 Raphaël Goulmot
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
  speed = key == sfKeyDown || key == sfKeyRight ? -5 : 0;
  if (speed)
    axe = key == sfKeyUp || key == sfKeyDown
      ? &scene->eye_pos.x : &scene->eye_pos.y;
  if (axe)
    *axe += speed;
}

void		commands(t_scene *scene, int key)
{
  t_object	*obj;

  if (scene->key_pressed == -1)
    scene->key_pressed = key;
  else if (scene->key_pressed != key)
    return;
  if (key == sfKeyUp || key == sfKeyDown
      || key == sfKeyLeft || key == sfKeyRight)
    move_view(scene, key);
  else if (scene->i_object && (obj = &scene->objects[scene->i_object])->type)
    {
      if (key == sfKeyZ || key == sfKeyS)
	obj->position.x += key == sfKeyZ ? 5 : -5;
      else if (key == sfKeyQ || key == sfKeyD)
	obj->position.y += key == sfKeyQ ? 5 : -5;
    }
  scene->refresh = true;
}

void		commands_off(t_scene *scene, int key)
{
  t_object	*obj;

  if (scene->key_pressed == key)
    {
      if (key == sfKeyPageUp || key == sfKeyPageDown)
	{
	  if (scene->i_object > -1
	      && (obj = &scene->objects[scene->i_object])->type)
	    obj->brillance -= 0.5;
	  scene->i_object += sfKeyPageUp == key ? 1 : -1;
	  if (scene->i_object < -1)
	    scene->i_object = -1;
	  else if (scene->i_object > -1
		   && (obj = &scene->objects[scene->i_object])->type)
	    obj->brillance += 0.5;
	  else if (scene->i_object > -1 && !obj->type)
	    scene->i_object += sfKeyPageUp == key ? -1 : 1;
	}
      scene->key_pressed = -1;
      scene->refresh = true;
    }
}
