/*
** sources.h for wireframe in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/wireframe/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Dec  4 18:33:16 2016 Antonin Rapini
** Last update Wed May 24 15:45:47 2017 Raphaël Goulmot
*/

#ifndef SOURCES_H_
# define SOURCES_H_

#include "my_raytracer.h"

#define READ_SIZE 128

void	my_handlekeypress(t_my_framebuffer *, float);
void	my_draw_scene(t_my_framebuffer *, t_scene *);
sfRenderWindow *my_create_window(char *, int, int);
sfVector3f calc_dir_vector(float, sfVector2i, sfVector2i);
sfVector3f translate(sfVector3f, sfVector3f);
sfVector3f rotate_xyz(sfVector3f, sfVector3f);
sfVector3f rotate_zyx(sfVector3f, sfVector3f);
float my_getsolution(float, float, float);
float get_light_coef(sfVector3f, sfVector3f);
t_object my_create_sphere(int, sfColor);
t_object my_create_plane(sfColor);
sfColor my_getcolor(t_scene *, sfVector3f);
t_object *my_create_objects();
char *get_next_line(int);
sfColor my_process_light(t_scene *, t_intersect *);
float my_getdist(t_object *, sfVector3f, sfVector3f, int);
void my_get_transformations(t_scene *scene);

/* my_display_loop.c */
void my_draw_scene(t_my_framebuffer *, t_scene *);
void my_draw_screen(sfRenderWindow *, t_screenelem *, t_scene *);
void my_display_loop(sfRenderWindow *, t_screenelem *, t_scene *);

/* my_framebuffer_utils.c */
t_my_framebuffer *my_create_framebuffer(int, int);
t_my_framebuffer *my_init_framebuffer();
void *my_free_framebuffer(t_my_framebuffer *);

/* my_raytracer_utils.c */
t_raytracer *my_create_raytracer(char *);
t_raytracer *my_init_raytracer();
void *my_free_raytracer(t_raytracer *);

/* my_screenelem_utils.c */
t_screenelem *my_create_screenelem(int, int);
t_screenelem *my_init_screenelem();
void *my_free_screenelem(t_screenelem *);

/* my_scene_utils.c */
t_light my_create_light(sfColor, int, sfVector3f);
t_scene *my_create_scene(char *);
t_scene *my_init_scene();
void *my_free_scene();

/* my_background_worker.c */
void launch_thread(t_scene *);

/* my_commands.c */
void commands(t_scene *, int);
void commands_off(t_scene *, int);

#endif /* !SOURCES_H_ */
