/*
** my_scene.h for raytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Feb 20 15:37:59 2017 Antonin Rapini
** Last update Wed Mar  8 16:11:26 2017 Antonin Rapini
*/

#ifndef MY_SCENE_H_
# define MY_SCENE_H_

#include <SFML/Graphics.h>
#include "my_light.h"
#include "my_object.h"

typedef struct	s_scene
{
  sfVector3f	eye_pos;
  sfVector2i	screen_size;
  t_object	*objects;
  t_light	*lights;
}		t_scene;

#endif /* !MY_SCENE_H_ */
