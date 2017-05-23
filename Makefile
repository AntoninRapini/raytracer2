##
## Makefile for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls
## 
## Made by Antonin Rapini
## Login   <antonin.rapini@epitech.net>
## 
## Started on  Tue Nov 29 08:50:17 2016 Antonin Rapini
## Last update Tue May 23 18:31:07 2017 Antonin Rapini
##

CFLAGS	+= -Wall -Werror -Wextra
CFLAGS 	+= -I include -g3

SRC	=	src/my_put_pixel.c		\
		src/calc_dir_vector.c		\
		src/translate.c			\
		src/rotate.c			\
		src/light.c			\
		src/utils.c			\
		utils/my_vector3_utils.c	\
		utils/my_abs.c			\
		utils/my_draw_line.c		\
		utils/my_getnbr.c		\
		utils/my_nbrlen.c		\
		utils/my_setalpha.c		\
		utils/my_clear_screen.c		\
		utils/my_create_sfvector3f.c	\
		utils/get_next_line.c		\
		utils/my_puterror.c		\
		utils/my_memset.c		\
		sources/my_create_window.c	\
		sources/my_screenelem_utils.c	\
		sources/my_raytracer_utils.c	\
		sources/my_framebuffer_utils.c	\
		sources/my_process_light.c	\
		sources/my_getdist.c		\
		sources/my_get_transformations.c	\
		sources/my_getcolor.c		\
		sources/my_scene_utils.c	\
		sources/my_objects_creation.c	\
		sources/my_create_objects.c	\
		sources/my_display_loop.c	\
		sources/objects/sphere.c	\
		sources/objects/plane.c		\
		sources/objects/cylinder.c	\
		sources/objects/cone.c		\
		raytracer2.c

OBJ	=	$(SRC:.c=.o)

NAME	=	raytracer2

$(NAME): $(OBJ)
	gcc $(OBJ) -g -lc_graph_prog -lm -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
