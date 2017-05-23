/*
** my_puterror.c for raytracer in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer2/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon May 22 21:00:19 2017 Antonin Rapini
** Last update Mon May 22 21:02:03 2017 Antonin Rapini
*/

#include <unistd.h>

int	my_puterror(char *str, int return_value)
{
  int	i;

  i = 0;
  while (str[i++]);
  write(2, str, i - 1);
  return (return_value);
}
