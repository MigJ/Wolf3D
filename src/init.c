/*
** init.c for  in /home/joubert/delivery/f_wolf3d/wolf3d
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Sun Jan 15 16:52:07 2017 Joubert Miguel
** Last update Sun Jan 15 21:48:59 2017 Joubert Miguel
*/

#include "../include/my.h"

t_window	init_pos_values(t_window W, char **av)
{
  W.pos.x = 14.0f;
  W.pos.y = 12.0f;
  W.dir.x = -1.f;
  W.dir.y = 0.f;
  W.plane.x = -0.50;
  W.plane.y = 0.66;
  W.time = 0.f;
  W.oldTime = 0.f;
  W.map = my_ret_map(av);
  W.mexit = 1;
  return (W);
}

t_window	init_time_values(t_window W, sfRenderWindow* window)
{
  W.mexit = sfRenderWindow_isOpen(window);
  W.oldTime = W.time;
  W.time = 0.f;
  W.frameTime = (W.time - W.oldTime) / 1000.0;
  W.moveSpeed = W.frameTime * 5.0;
  W.rotSpeed = W.frameTime * 3.0;
  return (W);
}

t_raycast	init_raycast_values(t_raycast R, sfVector2f pos,
				    sfVector2f dir, sfVector2f plane)
{
  R.map_co.x = pos.x;
  R.map_co.y = pos.y;
  R.ray_dir.x = dir.x + plane.x * R.cameraX;
  R.ray_dir.y = dir.y + plane.y * R.cameraX;
  R.delta.x =
    sqrt(1.f + (R.ray_dir.y * R.ray_dir.y) / (R.ray_dir.x * R.ray_dir.x));
  R.delta.y =
    sqrt(1.f + (R.ray_dir.x * R.ray_dir.x) / (R.ray_dir.y * R.ray_dir.y));
  R.hit = 0;
  R.step.x = (R.ray_dir.x < 0) ? -1 : 1;
  R.side_dist.x = (R.ray_dir.x < 0.f) ?
    (pos.x - R.map_co.x) * R.delta.x : (R.map_co.x + 1.0 - pos.x) * R.delta.x;
  R.step.y = (R.ray_dir.y < 0) ? -1 : 1;
  R.side_dist.y = (R.ray_dir.y < 0.f) ?
    (pos.y - R.map_co.y) * R.delta.y : (R.map_co.y + 1.0 - pos.y) * R.delta.y;
  return (R);
}
