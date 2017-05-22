/*
** sphere.c for raytracer in /home/hartwoom/Epitech/Infographie/raytracer1/src
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Tue Mar  7 17:02:24 2017 HartWoom
** Last update Thu Mar 16 14:34:26 2017 HartWoom
*/

#include "my.h"

float   intersect_sphere(sfVector3f eye, sfVector3f dir_v, float radius)
{
  float a;
  float b;
  float c;
  float delta;

  a = powf(dir_v.x, 2) + powf(dir_v.y, 2) + powf(dir_v.z, 2);
  b = 2 * ((eye.x * dir_v.x) + (eye.y * dir_v.y) + (eye.z * dir_v.z));
  c = powf(eye.x, 2) + powf(eye.y, 2) + powf(eye.z, 2) - powf(radius, 2);
  delta = powf(b, 2) - (4 * a * c);
  if (delta > 0)
    return (case_1(a, b, delta));
  else if (delta == 0)
    return (case_2(a, b));
  else if (delta < 0)
    return (-1);
  return (0);
}

sfVector3f	get_normal_sphere(sfVector3f intersection_point)
{
  sfVector3f	to_return;

  to_return.x = intersection_point.x;
  to_return.y = intersection_point.y;
  to_return.z = intersection_point.z;
  return (to_return);
}
