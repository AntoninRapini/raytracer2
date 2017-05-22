/*
** my_getsolution.c for raytracer1 in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer1/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Feb 25 17:55:16 2017 Antonin Rapini
** Last update Sat Mar 18 15:07:23 2017 Antonin Rapini
*/

#include <math.h>

float	my_getsolution(float a, float b, float c)
{
  float delta;
  float s1;
  float s2;

  delta = pow(b, 2) - 4 * a * c;
  if (a != 0)
    {
      if (delta == 0)
	return (-b / (2 * a));
      else if (delta > 0)
	{
	  s1 = (-b + sqrt(delta)) / (2 * a);
	  s2 = (-b - sqrt(delta)) / (2 * a);
	  return (s1 > 0 && (s1 < s2 || s2 < 0) ? s1 : s2 > 0 ? s2 : -1);
	}
    }
  return (-1);
}
