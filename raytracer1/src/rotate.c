/*
** rotate.c for raytracer in /home/hartwoom/Epitech/Infographie/raytracer1/src
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Tue Mar  7 16:59:50 2017 HartWoom
** Last update Wed Mar 22 16:43:12 2017 HartWoom
*/

#include "my.h"

sfVector3f	rotate_arround_x(sfVector3f vector, float angle)
{
  sfVector3f	to_return;

  angle = M_PI * angle / 180;
  to_return = vector;
  to_return.y = vector.y * cosf(angle) + vector.z * -sin(angle);
  to_return.z = vector.y * sinf(angle) + vector.z * cos(angle);
  return (to_return);
}

sfVector3f	rotate_arround_y(sfVector3f vector, float angle)
{
  sfVector3f	to_return;

  angle = M_PI * angle / 180;
  to_return = vector;
  to_return.x = vector.x * cos(angle) + vector.z * sin(angle);
  to_return.z = vector.x * -sin(angle) + vector.z * cos(angle);
  return (to_return);
}

sfVector3f	rotate_arround_z(sfVector3f vector, float angle)
{
  sfVector3f	to_return;

  angle = M_PI * angle / 180;
  to_return = vector;
  to_return.x = vector.x * cos(angle) + vector.y * -sin(angle);
  to_return.y = vector.x * sin(angle) + vector.y * cos(angle);
  return (to_return);
}

sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  to_rotate = rotate_arround_x(to_rotate, angles.x);
  to_rotate = rotate_arround_y(to_rotate, angles.y);
  to_rotate = rotate_arround_z(to_rotate, angles.z);
  return (to_rotate);
}

sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
  to_rotate = rotate_arround_z(to_rotate, angles.z);
  to_rotate = rotate_arround_y(to_rotate, angles.y);
  to_rotate = rotate_arround_x(to_rotate, angles.x);
  return (to_rotate);
}
