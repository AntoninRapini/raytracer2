/*
** utils.h for bootstrap_intro in /home/antonin.rapini/GraphicalProgramming/BootstrapIntroduction/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Nov 10 09:36:09 2016 Antonin Rapini
** Last update Tue Mar 14 22:20:06 2017 Antonin Rapini
*/

#ifndef UTILS_H_
# define UTILS_H_

#include <SFML/Graphics.h>
#include "my_framebuffer.h"
#include "my_screenelement.h"

sfRenderWindow		*create_window(char *, int, int);
t_my_framebuffer	*my_framebuffer_create(int, int);
void			my_put_pixel(t_my_framebuffer *, int, int, sfColor);
void my_draw_line (t_my_framebuffer *, sfVector2i, sfVector2i, sfColor);
float			my_abs(float);
int			my_getnbr(char *);
void			my_clear_screen(t_my_framebuffer *);
sfColor			my_setalpha(sfColor, float);
void			my_free_framebuffer(t_my_framebuffer *);
t_screenelem		*my_create_screenelem(int, int);
sfVector3f		my_create_sfvector3f(float, float, float);
sfVector3f		my_add_v3(sfVector3f, sfVector3f, int);
int my_nbrlen(int);

#endif /* !UTILS_H_ */
