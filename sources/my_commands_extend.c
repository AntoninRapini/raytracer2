/*
** my_commands_extend.c for raytracer2 in /home/raphael.goulmot/rendu/raytracer2
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Wed May 31 11:11:51 2017 Raphaël Goulmot
** Last update Thu Jun  1 10:30:20 2017 Raphaël Goulmot
*/

#include "sources.h"
#include "utils.h"

void	rotate_object(t_scene *scene, t_object *obj, int key)
{
  obj->rotation.x += sfKeyL == key ? -5 : sfKeyJ == key ? 5 : 0;
  obj->rotation.y += sfKeyI == key ? 5 : sfKeyK == key ? -5 : 0;
  scene = scene;
}
