/*
** my_commands.c for raytracer2 in /home/raphael.goulmot/rendu/raytracer2
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Wed May 24 15:25:44 2017 Raphaël Goulmot
** Last update Thu May 25 21:57:35 2017 Raphaël Goulmot
*/

#include <unistd.h>
#include "sources.h"
#include "utils.h"

void	commands(t_scene *scene, int key)
{
  if (scene->key_pressed == -1)
    scene->key_pressed = key;
  else if (scene->key_pressed != key)
    return;
  if (key == sfKeyUp || sfKeyDown == key)
    scene->eye_pos.x += key == sfKeyUp ? 5 : key == sfKeyDown ? -5 : 0;
  else if (key == sfKeyRight || sfKeyLeft)
    scene->eye_pos.y += key == sfKeyLeft ? 5 : key == sfKeyRight ? -5 : 0;
  scene->refresh = true;
}

void		commands_off(t_scene *scene, int key)
{
  t_object	*obj;

  if (scene->key_pressed == key)
    {
      if (key == sfKeyPageUp || key == sfKeyPageDown)
	{
	  if (scene->i_object > -1 && (obj = &scene->objects[scene->i_object])->type)
	    obj->brillance = 64;
	  scene->i_object += sfKeyPageUp == key ? 1 : -1;
	  if (scene->i_object < -1)
	    scene->i_object = -1;
	  else if (scene->i_object > -1 && (obj = &scene->objects[scene->i_object])->type)
	    obj->brillance = 64;
	  else if (scene->i_object > -1 && !obj->type)
	    scene->i_object += sfKeyPageUp == key ? -1 : 1;
	  my_putstr("Obj pos: ");
	  my_put_nbr(scene->i_object);
	  my_putchar('\n');
	}
      scene->key_pressed = -1;
      scene->refresh = true;
    }
}
