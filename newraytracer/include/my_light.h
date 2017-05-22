/*
** my_light.h for raytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Mar  7 19:24:35 2017 Antonin Rapini
** Last update Wed Mar  8 16:44:16 2017 Antonin Rapini
*/

#ifndef MY_LIGHT_H_
# define MY_LIGHT_H_

typedef struct s_light
{
  sfVector3f	position;
  sfVector3f	rotation;
  sfColor	color;
  float		brightness;
}		t_light;

#endif /* !MY_LIGHT_H_ */
