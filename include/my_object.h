/*
** my_object.h for raytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Feb 20 15:42:19 2017 Antonin Rapini
** Last update Thu Jun  1 01:45:50 2017 Antonin Rapini
*/

#ifndef MY_OBJECT_H_
# define MY_OBJECT_H_

#include <SFML/Graphics.h>

typedef struct  s_texture
{
  sfColor       **colors;
  sfVector2i    size;
}               t_texture;

typedef struct	s_object
{
  int		type;
  sfVector3f	position;
  sfVector3f	rotation;
  sfColor	color;
  sfColor	old_color;
  int		info;
  int		brillance;
  int		materialtype;
  float		transparency;
  float		refraction_i;
  float		reflection;
  char		*diffuse_map_filename;
  t_texture	*diffuse_map;
  char		*normal_map_filename;
  t_texture	*normal_map;
  sfVector3f	limited;
  sfVector3f	max;
  sfVector3f	min;
}		t_object;

typedef struct	s_intersect
{
  sfVector3f   	pos;
  sfVector3f   	normal;
  t_object	*obj;
  int		obj_i;
}		t_intersect;

typedef struct	s_ray
{
  sfVector3f	origin;
  sfVector3f	direction;
  float		distance;
  t_intersect	intersect;
  int		reflections;
}		t_ray;

typedef struct  s_bmpheader
{
  unsigned char magic[2];
  unsigned char filesize[4];
  unsigned char reserved[4];
  unsigned char offset[4];
  unsigned char headersize[4];
  unsigned char imagewidth[4];
  unsigned char imageheight[4];
  unsigned char colorplane[2];
  unsigned char bpp[2];
  unsigned char compressionmethod[4];
  unsigned char imagesize[4];
  unsigned char horizontalres[4];
  unsigned char verticalres[4];
  unsigned char colorpalette[4];
  unsigned char	importantcolors[4];
}               t_bmpheader;

/* sphere.c */
float intersect_sphere(t_object *, sfVector3f, sfVector3f);
sfVector3f get_normal_sphere(t_object *, sfVector3f);
sfVector2f get_sphere_uv(t_object *, sfVector3f);

/* cone.c */
float intersect_cone(t_object *, sfVector3f, sfVector3f);
sfVector3f get_normal_cone(t_object *, sfVector3f);
sfVector2f get_cone_uv(t_object *, sfVector3f);

/* cylinder.c */
float intersect_cylinder(t_object *, sfVector3f, sfVector3f);
sfVector3f get_normal_cylinder(t_object *, sfVector3f);
sfVector2f get_cylinder_uv(t_object *, sfVector3f);

/* plane.c */
float intersect_plane(t_object *, sfVector3f, sfVector3f);
sfVector3f get_normal_plane(t_object *, sfVector3f);
sfVector2f get_plane_uv(t_object *, sfVector3f);

#endif /* !MY_OBJECT_H_ */
