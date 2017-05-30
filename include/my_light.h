/*
** my_light.h for raytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Mar  7 19:24:35 2017 Antonin Rapini
** Last update Mon May 29 21:53:38 2017 Antonin Rapini
*/

#ifndef MY_LIGHT_H_
# define MY_LIGHT_H_

typedef struct s_light
{
  sfVector3f	position;
  sfVector3f	rotation;
  sfColor	color;
  float		specular;
  float		diffuse;
  float		brightness;
  float		radius;
}		t_light;

typedef struct	s_lightray
{
  sfColor	reflection;
  sfVector3f	reflection_v;
  sfColor	refraction;
  sfVector3f	refraction_v;
  sfVector3f	light_dir;
  float		distance;
  float		diffuse;
  float		specular;
  int		shadow;
  sfColor	final;
}		t_lightray;

#endif /* !MY_LIGHT_H_ */
