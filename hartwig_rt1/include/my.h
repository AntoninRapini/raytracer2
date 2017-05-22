/*
** my.h for raytracer in /home/antoine.hartwig/Epitech/Infographie/bsraytracer1/include
** 
** Made by Antoine Hartwig
** Login   <antoine.hartwig@epitech.net>
** 
** Started on  Wed Feb  8 08:15:05 2017 Antoine Hartwig
** Last update Wed Mar 22 15:17:38 2017 HartWoom
*/

#ifndef MY_H_
# define MY_H_

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "framebuff.h"

#define WIDTH 840
#define HEIGHT 680

typedef struct	s_ray
{
  sfVector3f	eyes;
  sfVector3f	light;
  sfVector2i	size;
  sfColor	col_sph;
  sfColor	col_pla;
}	t_ray;

void	set_struct(t_ray *);
sfColor	apply_light(t_ray *, sfVector3f, float, int);
void	my_framebuffer_destroy(t_my_framebuffer *);
void	my_put_pixel(t_my_framebuffer *, int, int, sfColor);
sfVector3f	calc_dir_vector(float, sfVector2i, sfVector2i);
float	intersect_plane(sfVector3f, sfVector3f);
float   intersect_sphere(sfVector3f, sfVector3f, float);
float	intersect_cylinder(sfVector3f, sfVector3f, float);
float	intersect_cone(sfVector3f, sfVector3f, float);
sfVector3f	get_normal_plane(int);
sfVector3f	get_normal_sphere(sfVector3f);
sfVector3f	get_normal_cylinder(sfVector3f);
sfVector3f	get_normal_cone(sfVector3f, float);
float	case_1(float, float, float);
float	case_2(float, float);
float	get_light_coef(sfVector3f, sfVector3f);
sfVector3f	intersect_point(sfVector3f, sfVector3f, float);
sfVector3f	calc_light_v(sfVector3f, sfVector3f);

#endif /* !MY_H_ */
