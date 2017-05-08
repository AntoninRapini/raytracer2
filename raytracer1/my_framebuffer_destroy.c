/*
** my_framebuffer_destroy.c for raytracer in /home/antoine.hartwig/Epitech/Infographie/bsraytracer1
** 
** Made by Antoine Hartwig
** Login   <antoine.hartwig@epitech.net>
** 
** Started on  Wed Feb  8 08:26:11 2017 Antoine Hartwig
** Last update Wed Feb  8 08:29:14 2017 Antoine Hartwig
*/

#include "include/my.h"

void	my_framebuffer_destroy(t_my_framebuffer *buff)
{
  free(buff);
}
