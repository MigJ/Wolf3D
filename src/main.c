/*
1;4205;0c** main.c for  in /home/joubert/delivery/wolf3d
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Mon Jan  2 22:37:53 2017 Joubert Miguel
** Last update Tue Feb 28 01:40:24 2017 Joubert Miguel
*/

#include "../include/my.h"


int	main(int ac, char **av)
{
  sfVideoMode   mode = {550, 450, 32};
  sfRenderWindow        *window;
  t_my_framebuffer	*framebuffer;
  sfTexture     *texture;
  sfSprite      *sprite;

  framebuffer = malloc(sizeof(*framebuffer));
  if (ac > 2)
    exit (84);
  window = sfRenderWindow_create(mode, "Wolf3d", sfResize | sfClose, NULL);
  sprite = sfSprite_create();
  texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  av[0] = 0;
  framebuffer = create_pixel_buffer();
  sfSprite_setTexture(sprite, texture, sfTrue);
  my_ret_map(av);
  open_window(window, sprite, framebuffer, av);
  sfSprite_destroy(sprite);
  sfTexture_destroy(texture);
  sfRenderWindow_destroy(window);
  return (0);
}
