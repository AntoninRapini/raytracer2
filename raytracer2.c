/*
** wireframe.c for wireframe in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/wireframe
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Dec  3 19:12:53 2016 Antonin Rapini
** Last update Tue May 23 05:56:09 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "sources.h"
#include "utils.h"

int		main(int ac, char **av)
{
  t_raytracer	*rt;

  if (ac >= 2)
    {
      if ((rt = my_create_raytracer(av[1])) != NULL)
	{
	  my_display_loop(rt->window, rt->screen, rt->scene);
	  my_free_raytracer(rt);
	  return (0);
	}
      else
	my_puterror("Scene creation failed.\n", 0);
    }
  else
    my_puterror("Not enough arguments, configuration file needed.\n", 0);
  return (84);
}
