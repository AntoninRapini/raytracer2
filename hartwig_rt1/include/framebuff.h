/*
** framebuff.h for raytracer in /home/hartwoom/Epitech/Infographie/raytracer1
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Wed Mar 22 16:42:07 2017 HartWoom
** Last update Wed Mar 22 16:42:08 2017 HartWoom
*/

#ifndef S_LIST_
# define S_LIST_

typedef struct	s_my_framebuffer
{
  sfUint8*	pixels;
  int  		width;
  int		height;
}		t_my_framebuffer;

t_my_framebuffer* my_framebuffer_create(int width, int height);

#endif
