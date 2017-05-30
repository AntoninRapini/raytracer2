##
## Makefile for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls
## 
## Made by Antonin Rapini
## Login   <antonin.rapini@epitech.net>
## 
## Started on  Tue Nov 29 08:50:17 2016 Antonin Rapini
## Last update Tue May 30 19:43:29 2017 romain pillot
##
CFLAGS	+= -Wall -Werror -Wextra
CFLAGS 	+= -lpthread -lm -lc_graph_prog -lX11 -I include -g3

SRCDIR		= sources
TRANSFORMS	= $(SRCDIR)/transformations
EFFECTS		= $(SRCDIR)/effects
OBJECTS		= $(SRCDIR)/objects
INIT		= $(SRCDIR)/init

SRC	=	config/boolean.c		\
		config/integer.c		\
		config/string.c			\
		config/print.c			\
		config/read.c			\
		config/config.c			\
		config/key.c			\
		config/array.c			\
		config/array_converter.c	\
		config/array_integer.c		\
		config/array_string.c		\
		config/free.c			\
		config/str/str_countchar.c	\
		config/str/str_contains.c	\
		config/str/str_split.c		\
		config/str/str_reduce.c		\
		config/str/str_length.c		\
		config/str/str_duplicate.c	\
		config/str/str_equals.c		\
		config/nbr/nbr_parsestring.c	\
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
		utils/my_color_utils.c		\
		utils/my_vector3_utils.c	\
		$(SRCDIR)/get_object_color.c	\
		$(SRCDIR)/my_loadtexture.c	\
		$(SRCDIR)/intersect.c		\
		$(SRCDIR)/my_put_pixel.c	\
		$(SRCDIR)/calc_dir_vector.c	\
		$(SRCDIR)/my_getsolution.c	\
		$(SRCDIR)/my_get_background.c	\
		$(SRCDIR)/fill_lightray.c	\
		$(SRCDIR)/my_get_normal.c	\
		$(SRCDIR)/my_minimap.c		\
		$(SRCDIR)/my_background_worker.c	\
		$(SRCDIR)/my_commands.c		\
		$(SRCDIR)/my_create_window.c	\
		$(SRCDIR)/my_process_light.c	\
		$(SRCDIR)/my_get_dist.c		\
		$(SRCDIR)/my_getcolor.c		\
		$(SRCDIR)/my_display_loop.c	\
		$(INIT)/my_create_lights.c	\
		$(INIT)/my_create_objects.c	\
		$(INIT)/my_framebuffer_utils.c	\
		$(INIT)/my_raytracer_utils.c	\
		$(INIT)/my_screenelem_utils.c	\
		$(INIT)/my_scene_utils.c	\
		$(OBJECTS)/sphere.c		\
		$(OBJECTS)/plane.c		\
		$(OBJECTS)/cylinder.c		\
		$(OBJECTS)/cone.c		\
		$(EFFECTS)/reflection.c		\
		$(EFFECTS)/refraction.c		\
		$(EFFECTS)/phong.c		\
		$(EFFECTS)/perlin.c		\
		$(TRANSFORMS)/translate.c	\
		$(TRANSFORMS)/rotate.c		\
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
