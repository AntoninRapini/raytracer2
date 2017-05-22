/*
** my_object.h for raytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Feb 20 15:42:19 2017 Antonin Rapini
** Last update Sun Mar 19 18:10:40 2017 Antonin Rapini
*/

#ifndef MY_OBJECT_H_
# define MY_OBJECT_H_

typedef struct	s_object
{
  int		type;
  sfVector3f	position;
  sfVector3f	rotation;
  sfColor	color;
  int		info;
  float		brillance;
}		t_object;

typedef struct	s_intersect
{
  sfVector3f   	pos;
  sfVector3f	origin;
  float		dist;
  int		obji;
  sfVector3f   	normal;
  t_object	obj;
}		t_intersect;

#endif /* !MY_OBJECT_H_ */
