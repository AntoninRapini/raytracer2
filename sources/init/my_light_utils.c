/*
** my_light_utils.c for raytracer in /home/antonin.rapini/ModulesTek1/GraphicalProgramming/raytracer2/sources/init
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed May 31 23:34:31 2017 Antonin Rapini
** Last update Wed May 31 23:41:19 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "sources.h"
#include "utils.h"

void	*my_free_lights(t_light **lights)
{
  int	i;

  i = 0;
  while (lights && lights[i])
    {
      free(lights[i]);
      i++;
    }
  return (NULL);
}

t_light		*my_init_light()
{
  t_light	*light;

  if ((light = malloc(sizeof(t_light))) == NULL)
    return (NULL);
  light->position = my_create_sfvector3f(0, 0, 0);
  light->rotation = my_create_sfvector3f(0, 0, 0);
  light->color = create_color(0, 0, 0);
  light->specular = 1;
  light->brightness = 1;
  light->diffuse = 1;
  light->radius = 0;
  return (light);
}
