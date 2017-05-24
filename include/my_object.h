/*
** my_object.h for raytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Feb 20 15:42:19 2017 Antonin Rapini
** Last update Wed May 24 22:42:40 2017 Antonin Rapini
*/

#ifndef MY_OBJECT_H_
# define MY_OBJECT_H_

#include <SFML/Graphics.h>

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

/* sphere.c */
float intersect_sphere(t_object *, sfVector3f, sfVector3f);
sfVector3f get_normal_sphere(t_object *, sfVector3f);

/* cone.c */
float intersect_cone(t_object *, sfVector3f, sfVector3f);
sfVector3f get_normal_cone(t_object *, sfVector3f);

/* cylinder.c */
float intersect_cylinder(t_object *, sfVector3f, sfVector3f);
sfVector3f get_normal_cylinder(t_object *, sfVector3f);

/* plane.c */
float intersect_plane(t_object *, sfVector3f, sfVector3f);
sfVector3f get_normal_plane(t_object *, sfVector3f);

#endif /* !MY_OBJECT_H_ */
