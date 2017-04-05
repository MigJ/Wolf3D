##
## Makefile for  in /home/arthur.despeaux/delivery/CPool_rush2
##
## Made by Arthur Despeaux
## Login   <arthur.despeaux@epitech.net>
##
## Started on  Sat Oct 15 17:13:33 2016 Arthur Despeaux
## Last update Sun Jan 15 18:37:41 2017 Joubert Miguel
##

PROJECT	=	src/my_put_pixel.c	\
		src/window.c		\
		src/init.c		\
		src/my_draw_line.c	\
		src/raycast.c		\
		src/move.c		\
		src/tools.c		\
		src/main.c		\

NAME	=	wolf3d

all:	$(NAME)

$(NAME):	$(PROJECT)
	$(CC) -g -W -Wall -Werror $(PROJECT) -o $(NAME) -lc_graph_prog -lm

clean:
	rm -f $(NAME)

fclean:	clean

re:	fclean	all
