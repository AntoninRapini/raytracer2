/*
** sources.h for raytracer2 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer2/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon May 29 16:55:34 2017 Antonin Rapini
** Last update Mon May 29 23:41:42 2017 Antonin Rapini
*/

#ifndef SOURCES_H_
# define SOURCES_H_

# include "my_raytracer.h"
# include <pthread.h>
# include "config.h"

# define READ_SIZE 1024

void	my_handlekeypress(t_my_framebuffer *, float);

/*** RAYTRACING ***/

void fill_lightray(t_scene *, t_light *, t_ray *, t_lightray *);
sfVector3f calc_dir_vector(float, sfVector2i, sfVector2i);
float my_getsolution(float, float, float);
sfColor my_process_light(t_scene *, t_ray *);
float my_get_dist(t_object *, sfVector3f, sfVector3f);
sfVector3f my_get_normal(t_object *, sfVector3f);

/* intersect.c */
void init_ray(t_ray *, sfVector3f, sfVector3f, int);
void find_intersect(t_object **, t_ray *, int);

/* my_getcolor.c */
sfColor my_getcolor(t_scene *, sfVector3f);

/* my_display_loop.c */
void my_draw_scene(t_my_framebuffer *, t_scene *);
void my_draw_screen(sfRenderWindow *, t_screenelem *, t_scene *);
void my_display_loop(sfRenderWindow *, t_screenelem *, t_scene *);

/*** TRANSFORMATIONS ***/
sfVector3f translate(sfVector3f, sfVector3f);
sfVector3f rotate_xyz(sfVector3f, sfVector3f);
sfVector3f rotate_zyx(sfVector3f, sfVector3f);
void my_get_transformations(t_scene *scene);

/*** STRUCT INIT ***/

sfRenderWindow *my_create_window(char *, int, int);

/* my_create_objects.c */
t_object **my_create_objects(t_config *);

/* my_create_lights.c */
t_light **my_create_lights(t_config *);

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
t_scene *my_create_scene(char *);
t_scene *my_init_scene();
void *my_free_scene();

/*** EFFECTS ***/

/* perlin.c */
float perlin_noise(float, float, float, int);

/* reflection.c */
sfVector3f my_get_reflection_vector(sfVector3f, sfVector3f);
sfColor my_get_reflection_color(t_ray *, sfVector3f, t_scene *);

/* refraction.c */
sfVector3f my_get_refraction_vector(sfVector3f, sfVector3f, float);
sfColor my_get_refraction_color(t_ray *, sfVector3f, t_scene *);

/* my_phong_utils.c */
float my_get_diffuse_coeff(sfVector3f, sfVector3f);
int my_get_shadow(t_lightray *, t_scene *, t_intersect *);
float euclidean_distance(sfVector3f, sfVector3f);


/*** HELPERS ***/

char *get_next_line(int);

/* my_vector3_utils.c */
sfVector3f my_add_to_v3(sfVector3f, float);
float my_dot_product(sfVector3f, sfVector3f);
sfVector3f norm_v3(sfVector3f);
sfVector3f my_add_v3(sfVector3f, sfVector3f, int);
sfVector3f my_mul_v3(sfVector3f, float);

/* my_background_worker.c */
void launch_thread(t_scene *, pthread_t *);

/* my_commands.c */
void commands(t_scene *, int);
void commands_off(t_scene *, int);

/* my_color_utils.c */
sfColor my_mul_colors(sfColor, sfColor);
sfColor my_mul_color(sfColor, float);
sfColor my_add_colors(sfColor, sfColor);
sfColor create_color(int, int, int);

/* my_minimap.c */
void display_minimap(t_scene *);

/* my_get_background.c */
sfColor my_get_background();

#endif /* !SOURCES_H_ */
