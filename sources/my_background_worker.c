/*
** my_background_worker.c for raytracer in /home/raphael.goulmot/rendu/raytracer2
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Wed May 24 14:55:37 2017 Raphaël Goulmot
** Last update Sun May 28 19:06:12 2017 Raphaël Goulmot
*/

#include <X11/Xlib.h>
#include <unistd.h>
#include "sources.h"
#include "utils.h"

static void	*background_worker(void *arg)
{
  t_scene	*scene;
  sfEvent	event;

  scene = (t_scene *)arg;
  while (scene->running && sfRenderWindow_isOpen(scene->window))
    {
      if (sfRenderWindow_pollEvent(scene->window, &event))
	{
	  if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1
	      || event.type == sfEvtClosed)
	    scene->running = false;
	  else if (event.type == sfEvtKeyPressed)
	    commands(scene, event.key.code);
	  else if (event.type == sfEvtKeyReleased)
	    commands_off(scene, event.key.code);
	}
    }
  pthread_exit(NULL);
}

void	launch_thread(t_scene *scene, pthread_t *bg)
{
  XInitThreads();
  if (pthread_create(bg, NULL, background_worker, (void *)scene) == -1)
    my_puterror("Thread creation failed.\n", 0);
}
