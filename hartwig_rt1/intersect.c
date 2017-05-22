/*
** intersect.c for raytracer in /home/hartwoom/Epitech/Infographie/raytracer1
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Wed Mar 22 10:40:57 2017 HartWoom
** Last update Wed Mar 22 10:45:34 2017 HartWoom
*/

#include "my.h"

sfVector3f	intersect_point(sfVector3f eye, sfVector3f dir_v, float k)
{
  sfVector3f	inter;

  inter.x = eye.x + (k * dir_v.x);
  inter.y = eye.y + (k * dir_v.y);
  inter.z = eye.z + (k * dir_v.z);
  return (inter);
}
