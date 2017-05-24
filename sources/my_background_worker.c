/*
** my_background_worker.c for raytracer in /home/raphael.goulmot/rendu/raytracer2
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Wed May 24 14:55:37 2017 Raphaël Goulmot
** Last update Wed May 24 16:14:01 2017 Raphaël Goulmot
*/

#include <pthread.h>
#include <unistd.h>
#include "sources.h"
#include "utils.h"

static void	*background_worker(void *arg)
{
  t_scene	*scene;
  bool		lock;

  scene = (t_scene *)arg;
  lock = false;
  while (scene->running)
    {
      if (scene->refresh && !lock)
	{
	  lock = true;
	  my_draw_screen(scene->window, scene->screen, scene);
	  lock = false;
	  scene->refresh = 0;
	}
    }
  pthread_exit(NULL);
}

void	launch_thread(t_scene *scene)
{
  pthread_t	bg;

  if (pthread_create(&bg, NULL, background_worker, (void *)scene) == -1)
    my_puterror("Thread creation failed.\n", 0);
}
