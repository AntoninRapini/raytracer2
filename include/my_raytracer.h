/*
** my_raytracer.h for raytracer2 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer2/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon May 22 21:38:56 2017 Antonin Rapini
** Last update Wed May 24 22:25:32 2017 Antonin Rapini
*/

#ifndef MY_RAYTRACER_H_
# define MY_RAYTRACER_H_

# include <SFML/Graphics.h>
# include "my_light.h"
# include "my_object.h"
# include <stdbool.h>

# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 720

typedef float (*INTERSECT_FUNC)(t_object *, sfVector3f, sfVector3f);
typedef  sfVector3f (*NORMAL_FUNC)(t_object *, sfVector3f);

typedef struct  s_my_framebuffer
{
  sfUint8       *pixels;
  int           width;
  int           height;
}               t_my_framebuffer;

typedef struct          s_screenelem
{
  sfSprite              *sprite;
  sfTexture             *texture;
  t_my_framebuffer      *frb;
}                       t_screenelem;

typedef struct		s_scene
{
  bool			refresh;
  bool			running;
  int			key_pressed;
  sfRenderWindow	*window;
  t_screenelem		*screen;
  sfVector3f		eye_pos;
  sfVector3f		eye_rot;
  sfVector2i		screen_size;
  t_object		*objects;
  t_light		*lights;
}			t_scene;

typedef struct		s_raytracer
{
  sfRenderWindow	*window;
  t_screenelem		*screen;
  t_scene		*scene;
}			t_raytracer;

#endif /* !MY_RAYTRACER_H_ */
