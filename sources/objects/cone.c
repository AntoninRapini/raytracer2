/*
** my_sphere_intersection.c for 104intersection in /home/antonin.rapini/ModulesTek1/MathematicalProgramming/my104intersection/operations
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Jan  1 16:54:57 2017 Antonin Rapini
** Last update Thu Jun  1 03:41:23 2017 Antonin Rapini
*/

#include <math.h>
#include "sources.h"

float	intersect_cone(t_object *obj, sfVector3f pos, sfVector3f dir)
{
  float a;
  float b;
  float c;
  float cte;

  cte = pow(tanf(obj->info * (M_PI / 180)), 2);
  a = pow(dir.x, 2) + pow(dir.y, 2) - (pow(dir.z, 2) * cte);
  b = 2 * (pos.x * dir.x) + 2 * (dir.y * pos.y)
    - ((2 * ((dir.z * pos.z))) * cte);
  c = pow(pos.x, 2) + pow(pos.y, 2) - (pow(pos.z, 2) * cte);
  return (my_getsolution(a, b, c));
}

sfVector3f	get_normal_cone(t_object *obj, sfVector3f ip)
{
  sfVector3f	v;
  float		m;
  sfVector3f	n;

  v.x = ip.x - obj->position.x;
  v.y = 0;
  v.z = ip.z - obj->position.z;
  m = sqrt(pow(v.x, 2) + pow(v.z, 2));
  v.x = v.x / m;
  v.z = v.z / m;
  n.x = v.x;
  n.y = 1;
  n.z = 1;
  return (n);
}

sfVector2f	get_cone_uv(t_object *obj, sfVector3f ip)
{
  sfVector2f	uv;

  uv.x = 0;
  uv.y = 0;
  if (obj && ip.x)
    {
    }
  return (uv);
}
