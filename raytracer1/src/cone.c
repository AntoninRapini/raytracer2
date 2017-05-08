/*
** cone.c for raytracer in /home/hartwoom/Epitech/Infographie/raytracer1/src
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Tue Mar  7 17:28:23 2017 HartWoom
** Last update Thu Mar 16 15:32:53 2017 HartWoom
*/

#include "my.h"

float	intersect_cone(sfVector3f eye, sfVector3f dir_v, float semiangle)
{
  float	a;
  float	b;
  float c;
  float p;
  float delta;

  if ((p = powf(atan(semiangle), 2)) == 0)
    return (-1);
  a = powf(dir_v.x, 2) + powf(dir_v.y, 2) - powf(dir_v.z, 2) / p;
  b = (2 * eye.x * dir_v.x) + (2 * eye.y * dir_v.y) + (2 * eye.z * dir_v.z) / p;
  c = powf(eye.x, 2) + powf(eye.y, 2) - powf(eye.z, 2) / p;
  delta = powf(b, 2) - (4 * a * c);
  if (delta > 0)
    return (case_1(a, b, delta));
  else if (delta == 0)
    return (case_2(a, b));
  else if (delta < 0)
    return (-1);
  return (0);
}

sfVector3f	get_normal_cone(sfVector3f intersection_point, float semiangle)
{
  sfVector3f	to_return;

  semiangle = M_PI * semiangle / 180;
  to_return.x = intersection_point.x;
  to_return.y = intersection_point.y;
  to_return.z = -atan(semiangle) * intersection_point.z;
  return (to_return);
}
