/*
** my_draw_line.c for  in /home/joubert/delivery/wolf3d
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Mon Jan  2 22:51:13 2017 Joubert Miguel
** Last update Sun Jan 15 21:50:40 2017 Joubert Miguel
*/

#include "../include/my.h"

sfVector2i	my_vector_co(int x, int y)
{
  sfVector2i	co;

  co.x = x, co.y = y;
  return (co);
}

t_draw_line	init_params(t_draw_line L, sfVector2i from, sfVector2i to)
{
  L.i = 1;
  L.xinc = (to.x - from.x > 0) ? 1 : -1;
  L.yinc = (to.y - from.y > 0) ? 1 : -1;
  L.cumul = (to.x > to.y) ? to.x / 2 : to.y /2;
  return (L);
}

sfVector2i	init_direction(sfVector2i from, sfVector2i to)
{
  to.x = abs(to.x - from.x);
  to.y = abs(to.y - from.y);
  return (to);
}

void	my_draw_line(t_my_framebuffer *framebuffer, sfVector2i from,
		     sfVector2i to, sfColor color)
{
  t_draw_line	L;

  L = init_params(L, from, to);
  to = init_direction(from, to);
  my_put_pixel(framebuffer, from.x,from.y, color);
  if (to.x > to.y)
    {
      while (L.i++ <= to.x)
	{
	  from.x += L.xinc;
	  L.cumul += to.y;
	  (L.cumul >= to.x) ? L.cumul -= to.x, from.y += L.yinc : 0;
	  my_put_pixel(framebuffer, from.x, from.y, color);
	}
    }
  else
    {
      while (L.i++ <= to.y)
	{
	  from.y += L.yinc;
	  L.cumul += to.x;
	  (L.cumul >= to.y) ? L.cumul -= to.y, from.x += L.xinc : 0;
	  my_put_pixel(framebuffer, from.x, from.y, color);
	}
    }
}
