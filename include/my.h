/*
** my.h for d09 in /home/arthur.despeaux/delivery/CPool_Day09/include/
**
** Made by Arthur Despeaux
** Login   <arthur.despeaux@epitech.eu@epitech.eu>
**
** Started on  Thu Oct 13 09:18:14 2016 Arthur Despeaux
** Last update Sun Jan 15 22:04:29 2017 Joubert Miguel
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mylist.h"

#define SCREEN_WIDTH 550
#define SCREEN_HEIGHT 450

#ifndef MY_H
#define MY_H

t_my_framebuffer        *create_pixel_buffer();

void    my_put_pixel(t_my_framebuffer *framebuffer,
		     int x, int y, sfColor color);

int     open_window(sfRenderWindow* window, sfSprite *sprite,
		    t_my_framebuffer *framebuffer, char **av);

sfVector2i      my_vector_co(int x, int y);

void	my_draw_line(t_my_framebuffer *framebuffer, sfVector2i from,
		     sfVector2i to, sfColor color);

sfVector2f      move_forward(sfVector2f pos, float direction, float distance);

int	**my_ret_map(char **av);

int	my_count_lines(char *str);

int     my_count_char(char *str, int i);

void    my_draw_walls(t_window W, sfSprite *sprite,
		      t_my_framebuffer *framebuffer);

sfVector2f      down(sfVector2f dir, sfVector2f pos,
		     float moveSpeed, int **map);

sfVector2f      up(sfVector2f dir, sfVector2f pos, float moveSpeed, int **map);

t_window	right(t_window W);

t_window      left(t_window W);

t_window        init_pos_values(t_window W, char **av);

t_window        init_time_values(t_window W, sfRenderWindow* window);

float   raycast(t_window W);

t_raycast       init_raycast_values(t_raycast R, sfVector2f pos,
				    sfVector2f dir, sfVector2f plane);

t_window        screen_loop(t_window W, sfRenderWindow* window,
			    sfSprite *sprite, t_my_framebuffer *framebuffer);

#endif
