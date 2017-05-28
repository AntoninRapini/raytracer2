/*
** my_light.h for raytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Mar  7 19:24:35 2017 Antonin Rapini
** Last update Sun May 28 19:20:26 2017 Antonin Rapini
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

typedef struct	s_rayhitinfos
{
  sfColor	reflection;
  sfColor	refraction;
  sfVector3f	light_dir;
  sfVector3f	reflection_v;
  sfVector3f	refraction_v;
  float		diffuse;
  float		specular;
  int		shadowed;
  sfColor	final;
  float		distance;
}		t_rayhitinfos;

#endif /* !MY_LIGHT_H_ */
