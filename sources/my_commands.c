/*
** my_commands.c for raytracer2 in /home/raphael.goulmot/rendu/raytracer2
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Wed May 24 15:25:44 2017 Raphaël Goulmot
** Last update Wed May 24 16:13:45 2017 Raphaël Goulmot
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

void	commands_off(t_scene *scene, int key)
{
  if (scene->key_pressed == key)
    {
      scene->key_pressed = -1;
      scene->refresh = true;
    }
}
