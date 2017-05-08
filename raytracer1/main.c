/*
** main.c for raytracer in /home/antoine.hartwig/Epitech/Infographie/bsraytracer1
** 
** Made by Antoine Hartwig
** Login   <antoine.hartwig@epitech.net>
** 
** Started on  Thu Feb 23 16:35:40 2017 Antoine Hartwig
** Last update Tue Apr 25 11:52:45 2017 HartWoom
*/

#include "include/my.h"

sfColor	what_to_draw(t_ray *ray, sfVector3f vect, float s, float p)
{
  if (s < 0 && p < 0)
    return (sfBlack);
  if (s >= 0 && p <= 0)
    return (apply_light(ray, vect, s, 1));
  if (s > 0 && p > 0)
    {
      if (s >= p)
	return (apply_light(ray, vect, p, 2));
      else if (s < p)
	return (apply_light(ray, vect, s, 1));
    }
  if (s < 0 && p > 0)
    return (apply_light(ray, vect, p, 2));
  return (sfBlack);
}

int		raytrace_scene(t_my_framebuffer *framebuffer)
{
  t_ray		*ray;
  sfVector2i	pos = {0, 0};
  sfVector3f	vect;

  if (!(ray = malloc(sizeof(t_ray))))
    return (84);
  set_struct(ray);
  while (pos.x != ray->size.x || pos.y != ray->size.y)
    {
      vect = calc_dir_vector(200, ray->size, pos);
      my_put_pixel(framebuffer, pos.x, pos.y,
		   what_to_draw(ray, vect,
				intersect_sphere(ray->eyes, vect, 60.0),
				intersect_plane(ray->eyes, vect)));
      if (pos.x == ray->size.x)
	{
	  pos.y++;
	  pos.x = 0;
	}
      else
	pos.x++;
    }
  return (0);
}

int		process_game_loop(sfRenderWindow *window, sfSprite *sprite)
{
  sfEvent	event;

  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
	    sfRenderWindow_close(window);
	  if (event.type == sfEvtClosed)
	    sfRenderWindow_close(window);
	}
      sfRenderWindow_clear(window, sfBlack);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_display(window);
    }
  return (0);
}

int	main()
{
  sfVideoMode		mode = {WIDTH, HEIGHT, 32};
  sfRenderWindow	*window;
  sfTexture		*texture;
  sfSprite		*sprite;
  t_my_framebuffer	*framebuffer;

  window = sfRenderWindow_create(mode, "Raytracer 1",
				 sfResize | sfClose, NULL);
  framebuffer = malloc(sizeof(t_my_framebuffer));
  framebuffer = my_framebuffer_create(WIDTH, HEIGHT);
  sprite = sfSprite_create();
  texture = sfTexture_create(WIDTH, HEIGHT);
  sfSprite_setTexture(sprite, texture, sfTrue);

  raytrace_scene(framebuffer);
  sfTexture_updateFromPixels(texture, framebuffer->pixels
			     , framebuffer->width, framebuffer->height, 0,0);
  process_game_loop(window, sprite);
  my_framebuffer_destroy(framebuffer);
  sfSprite_destroy(sprite);
  sfTexture_destroy(texture);
  sfRenderWindow_destroy(window);
  return (0);
}
