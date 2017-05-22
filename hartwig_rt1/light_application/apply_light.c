/*
** apply_light.c for raytracer in /home/hartwoom/Epitech/Infographie/raytracer1
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Wed Mar 22 14:29:11 2017 HartWoom
** Last update Thu Mar 23 09:59:39 2017 HartWoom
*/

#include "my.h"

sfColor		apply_light(t_ray *ray, sfVector3f vect, float k, int obj)
{
  sfVector3f	inter;
  sfVector3f	light_v;
  float		coef;
  sfColor	tmp;

  inter = intersect_point(ray->eyes, vect, k);
  light_v = calc_light_v(inter, ray->light);
  if (obj == 1)
    {
      coef = get_light_coef(light_v, get_normal_cone(inter, 25));
      tmp = ray->col_sph;
      tmp.a *= coef;
      return (tmp);
    }
  else if (obj == 2)
    {
      coef = get_light_coef(light_v, get_normal_plane(1));
      tmp = ray->col_pla;
      tmp.a *= coef;
      return (tmp);
    }
  return (sfBlack);
}
