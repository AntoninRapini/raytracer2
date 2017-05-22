/*
** set_struct.c for raytracer in /home/hartwoom/Epitech/Infographie/raytracer1
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Wed Mar 22 09:55:40 2017 HartWoom
** Last update Tue Apr 25 11:52:30 2017 HartWoom
*/

#include "my.h"

void	set_struct(t_ray *ray)
{
  ray->eyes.x = -175;
  ray->eyes.y = 40;
  ray->eyes.z = 75;
  ray->light.x = -10;
  ray->light.y = 220;
  ray->light.z = 40;
  ray->size.x = WIDTH;
  ray->size.y = HEIGHT;
  ray->col_sph.r = 255;
  ray->col_sph.g = 128;
  ray->col_sph.b = 0;
  ray->col_sph.a = 255;
  ray->col_pla.r = 0;
  ray->col_pla.g = 153;
  ray->col_pla.b = 76;
  ray->col_pla.a = 255;
}
