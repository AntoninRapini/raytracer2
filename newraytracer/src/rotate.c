/*
** my_rotate.c for wireframe in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/wireframe/bonus/transformations
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Dec  8 22:50:27 2016 Antonin Rapini
** Last update Sat Mar 18 15:05:59 2017 Antonin Rapini
*/

#include <math.h>
#include <SFML/Graphics.h>

sfVector3f	x_rotation(sfVector3f point, float rot)
{
  float		angle;
  float		y;

  y = point.y;
  angle = rot * (M_PI / 180);
  point.y = y * cosf(angle) - point.z * sinf(angle);
  point.z = y * sinf(angle) + point.z * cosf(angle);
  return (point);
}

sfVector3f	y_rotation(sfVector3f point, float rot)
{
  float		angle;
  float		x;

  x = point.x;
  angle = rot * (M_PI / 180);
  point.x = x * cosf(angle) + point.z * sinf(angle);
  point.z = -x * sinf(angle) + point.z * cosf(angle);
  return (point);
}

sfVector3f	z_rotation(sfVector3f point, float rot)
{
  float		angle;
  float		x;

  x = point.x;
  angle = rot * (M_PI / 180);
  point.x = x * cosf(angle) - point.y * sinf(angle);
  point.y = x * sinf(angle) + point.y * cosf(angle);
  return (point);
}

sfVector3f rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  if (angles.x != 0)
    to_rotate = x_rotation(to_rotate, angles.x);
  if (angles.y != 0)
    to_rotate = y_rotation(to_rotate, angles.y);
  if (angles.z != 0)
    to_rotate = z_rotation(to_rotate, angles.z);
  return (to_rotate);
}

sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
  if (angles.z != 0)
    to_rotate = z_rotation(to_rotate, angles.z);
  if (angles.y != 0)
    to_rotate = y_rotation(to_rotate, angles.y);
  if (angles.x != 0)
    to_rotate = x_rotation(to_rotate, angles.x);
  return (to_rotate);
}
