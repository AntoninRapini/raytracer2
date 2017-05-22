/*
** utils.h for bootstrap_intro in /home/antonin.rapini/GraphicalProgramming/BootstrapIntroduction/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Nov 10 09:36:09 2016 Antonin Rapini
** Last update Tue Mar  7 19:06:31 2017 Antonin Rapini
*/

#ifndef MY_FRAMEBUFFER_H_
# define MY_FRAMEBUFFER_H_

#include <SFML/Graphics.h>

typedef struct		s_my_framebuffer
{
  sfUint8	        *pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

#endif /* !MY_FRAMEBUFFER_H_ */
