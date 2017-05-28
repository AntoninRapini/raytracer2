##
## Makefile for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls
## 
## Made by Antonin Rapini
## Login   <antonin.rapini@epitech.net>
## 
## Started on  Tue Nov 29 08:50:17 2016 Antonin Rapini
## Last update Sun May 28 18:25:41 2017 romain pillot
##
CFLAGS	+= -Wall -Werror -Wextra
CFLAGS 	+= -lpthread -lm -lc_graph_prog -lX11 -I include -g3

SRC	=	config/boolean.c		\
		config/integer.c		\
		config/string.c			\
		config/print.c			\
		config/read.c			\
		config/config.c			\
		config/key.c			\
		config/array.c			\
		config/free.c			\
		config/str/str_countchar.c	\
		config/str/str_split.c		\
		config/str/str_reduce.c		\
		config/str/str_length.c		\
		config/str/str_duplicate.c	\
		config/str/str_equals.c		\
		config/nbr/nbr_parsestring.c	\
		src/my_put_pixel.c		\
		src/calc_dir_vector.c		\
		src/translate.c			\
		src/rotate.c			\
		src/light.c			\
		src/utils.c			\
		utils/my_miniprintf.c		\
		utils/my_display_utils.c	\
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
		sources/my_fill_rayhitinfos.c	\
		sources/my_get_reflection.c	\
		sources/my_phong_utils.c	\
		sources/my_color_utils.c	\
		sources/my_vector3_utils.c	\
		sources/my_get_normal.c		\
		sources/my_minimap.c		\
		sources/my_background_worker.c	\
		sources/my_commands.c		\
		sources/my_create_window.c	\
		sources/my_screenelem_utils.c	\
		sources/my_raytracer_utils.c	\
		sources/my_framebuffer_utils.c	\
		sources/my_process_light.c	\
		sources/my_get_dist.c		\
		sources/my_get_transformations.c\
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
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
