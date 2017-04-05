/*
** raycast.c for  in /home/joubert/delivery/wolf3d
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Jan  3 14:02:27 2017 Joubert Miguel
** Last update Sun Jan 15 21:52:06 2017 Joubert Miguel
*/

#include "../include/my.h"

float	raycast(t_window W)
{
  t_raycast	R;

  R.cameraX = 2.0 * W.x / ((float) SCREEN_WIDTH) - 1.0;
  R = init_raycast_values(R, W.pos, W.dir, W.plane);
  while (R.hit == 0)
    {
      if (R.side_dist.x < R.side_dist.y)
	{
	  R.side_dist.x += R.delta.x;
	  R.map_co.x += R.step.x;
	  R.side = 0;
	}
      else
	{
	  R.side_dist.y += R.delta.y;
	  R.map_co.y += R.step.y;
	  R.side = 1;
	}
      (W.map[R.map_co.x][R.map_co.y] > 0) ? R.hit = 1 : 0;
    }
  R.perpWallDist = (R.side == 0) ?
    (R.map_co.x - W.pos.x + (1.f - R.step.x) / 2.f) / R.ray_dir.x :
    (R.map_co.y - W.pos.y + (1.f - R.step.y) / 2.f) / R.ray_dir.y;
  return (R.perpWallDist);
}

void	my_draw_walls(t_window W, sfSprite *sprite, t_my_framebuffer *framebuffer)
{
  sfVector2i from;
  sfVector2i to;
  int lineHeight;
  int drawStart;
  int drawEnd;

  lineHeight = (int)(SCREEN_HEIGHT / W.perpWallDist);
  drawStart= -lineHeight / 2 + SCREEN_HEIGHT / 2;
  (drawStart < 0) ? drawStart = 0 : 0;
  drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
  (drawEnd >= SCREEN_HEIGHT) ? drawEnd = SCREEN_HEIGHT - 1 : 0;
  from = my_vector_co(W.x, drawStart);
  to = my_vector_co(W.x, drawEnd);
  sfSprite_setTexture(sprite, W.texture, sfTrue);
  my_draw_line(framebuffer, from, to, sfBlack);
  sfTexture_updateFromPixels(W.texture, framebuffer->pixels,
			     SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
}
