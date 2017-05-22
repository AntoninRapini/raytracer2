##
## Makefile for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls
## 
## Made by Antonin Rapini
## Login   <antonin.rapini@epitech.net>
## 
## Started on  Tue Nov 29 08:50:17 2016 Antonin Rapini
## Last update Sun Mar 19 17:44:38 2017 Antonin Rapini
##

CFLAGS	+= -Wall -Werror -Wextra
CFLAGS 	+= -I include

SRC	=	src/my_put_pixel.c		\
		src/calc_dir_vector.c		\
		src/translate.c			\
		src/rotate.c			\
		src/sphere.c			\
		src/plane.c			\
		src/cylinder.c			\
		src/light.c			\
		src/cone.c			\
		src/utils.c			\
		utils/my_vector3_utils.c	\
		utils/create_window.c		\
		utils/my_abs.c			\
		utils/my_framebuffer_create.c	\
		utils/my_draw_line.c		\
		utils/my_create_screenelem.c	\
		utils/my_getnbr.c		\
		utils/my_nbrlen.c		\
		utils/my_setalpha.c		\
		utils/my_clear_screen.c		\
		utils/my_create_sfvector3f.c	\
		utils/get_next_line.c		\
		sources/my_process_light.c	\
		sources/my_getdist.c		\
		sources/my_get_transformations.c	\
		sources/my_getcolor.c		\
		sources/my_create_scene.c	\
		sources/my_draw_scene.c		\
		sources/my_objects_creation.c	\
		sources/my_create_objects.c	\
		sources/my_display.c		\
		raytracer1.c

OBJ	=	$(SRC:.c=.o)

NAME	=	raytracer1

$(NAME): $(OBJ)
	gcc $(OBJ) -g -lc_graph_prog -lm -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
