/*
** sources.h for wireframe in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/wireframe/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Dec  4 18:33:16 2016 Antonin Rapini
** Last update Sun Mar 19 18:05:10 2017 Antonin Rapini
*/

#ifndef SOURCES_H_
# define SOURCES_H_

#include "my_framebuffer.h"
#include "my_scene.h"

#define READ_SIZE 128

int	my_display(int, int);
void	my_free_framebuffer(t_my_framebuffer *);
void	my_handlekeypress(t_my_framebuffer *, float);
void	my_draw_scene(t_my_framebuffer *, t_scene *);
sfVector3f calc_dir_vector(float, sfVector2i, sfVector2i);
float intersect_sphere(sfVector3f, sfVector3f, float);
float intersect_plane(sfVector3f, sfVector3f);
float intersect_cylinder(sfVector3f, sfVector3f, float);
float intersect_cone(sfVector3f, sfVector3f, float);
sfVector3f get_normal_sphere(sfVector3f);
sfVector3f get_normal_cylinder(sfVector3f);
sfVector3f get_normal_plane(int);
sfVector3f get_normal_cone(sfVector3f, float);
sfVector3f translate(sfVector3f, sfVector3f);
sfVector3f rotate_xyz(sfVector3f, sfVector3f);
sfVector3f rotate_zyx(sfVector3f, sfVector3f);
float my_getsolution(float, float, float);
float get_light_coef(sfVector3f, sfVector3f);
t_scene *my_create_scene(int, int);
t_object my_create_sphere(int, sfColor);
t_object my_create_plane(sfColor);
t_light my_create_light(sfColor, int, sfVector3f);
sfColor my_getcolor(t_scene *, sfVector3f);
t_object *my_create_objects();
char *get_next_line(int);
sfColor my_process_light(t_scene *, t_intersect *);
float my_getdist(t_object *, sfVector3f, sfVector3f, int);
void my_get_transformations(t_scene *scene);

#endif /* !SOURCES_H_ */
