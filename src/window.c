/*
** window.c for  in /home/joubert/delivery/wolf3d
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Mon Jan  2 22:38:25 2017 Joubert Miguel
** Last update Tue Feb 28 01:54:54 2017 Joubert Miguel
*/

#include "../include/my.h"

void	clear_all_pixels(t_my_framebuffer *framebuffer)
{
  int	i;
  int	j;

  i = j = 0;
  while (i <= SCREEN_WIDTH)
    {
      while (j < SCREEN_HEIGHT / 2)
	{
	  my_put_pixel(framebuffer, i, j, sfCyan);
	  j++;
	}
      while (j <= SCREEN_HEIGHT)
	{
	  my_put_pixel(framebuffer, i, j, sfWhite);
	  j++;
	}
      j = 0;
      i++;
    }
}

t_window	screen_loop(t_window W, sfRenderWindow* window,
			    sfSprite *sprite, t_my_framebuffer *framebuffer)
{
  W.x = 0.f;
  W.time +=22;
  W.texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  while (W.x < SCREEN_WIDTH)
    {
      W.x += 0.3;
      W.perpWallDist = raycast(W);
      my_draw_walls(W, sprite, framebuffer);
    }
  sfRenderWindow_drawSprite(window, sprite, NULL);
  sfRenderWindow_display(window);
  return (W);
}

int	open_window(sfRenderWindow* window, sfSprite *sprite,
		    t_my_framebuffer *framebuffer, char **av)
{
  t_window	W;

  W = init_pos_values(W, av);
  sfRenderWindow_setFramerateLimit(window, 30);
  if (!window)
    return (84);
  while (sfRenderWindow_isOpen(window))
    {
      sfRenderWindow_clear(window, sfWhite);
      clear_all_pixels(framebuffer);
      W = init_time_values(W, window);
      while (sfRenderWindow_pollEvent(window, &W.event))
	{
	  if (W.event.type == sfEvtClosed)
	    sfRenderWindow_close(window);
	  if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	    sfRenderWindow_close(window);
	  if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
	    W.pos = down(W.dir, W.pos, W.moveSpeed, W.map);
	  if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
	    W.pos = up(W.dir, W.pos, W.moveSpeed, W.map);
	  if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) W = right(W);
	  if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) W = left(W);
	}
      W = screen_loop(W, window, sprite, framebuffer);
      W.mexit = 0;
    }
  return (0);
}
