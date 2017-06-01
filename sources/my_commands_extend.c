/*
** my_commands_extend.c for raytracer2 in /home/raphael.goulmot/rendu/raytracer2
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Wed May 31 11:11:51 2017 Raphaël Goulmot
** Last update Thu Jun  1 10:23:37 2017 Raphaël Goulmot
*/

#include "sources.h"
#include "utils.h"

void	rotate_object(t_scene *scene, t_object *obj, int key)
{
  sfVector3f	new;
  sfVector3f	rot;

  key = key;
  new = my_create_sfvector3f(obj->rotation.x
			     , obj->rotation.y, obj->rotation.z);
  rot = my_create_sfvector3f(0, new.y + (sfKeyI == key
				? 5 : sfKeyK == key ? -5 : 0), 0);
  obj->rotation = rotate_zyx(new, rot);
  scene = scene;
}
