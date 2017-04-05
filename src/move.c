/*
** move.c for  in /home/joubert/delivery/f_wolf3d/wolf3d/src
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Sun Jan 15 15:36:46 2017 Joubert Miguel
** Last update Mon Feb 13 14:08:18 2017 Joubert Miguel
*/

#include "../include/my.h"

sfVector2f	down(sfVector2f dir, sfVector2f pos, float moveSpeed, int **map)
{
  sfVector2i	cor;

  cor.x = ((int)pos.x + dir.x * moveSpeed);
  cor.y = ((int)pos.y + dir.y * moveSpeed);
  (map[cor.x][(int)pos.y] == 0) ? pos.x += dir.x * moveSpeed : 0;
  (map[(int)pos.x][cor.y] == 0) ? pos.y += dir.y * moveSpeed : 0;
  return (pos);
}

sfVector2f	up(sfVector2f dir, sfVector2f pos, float moveSpeed, int **map)
{
  sfVector2i	cor;

  cor.x = (int)pos.x - dir.x * moveSpeed;
  cor.y = (int)pos.y - dir.y * moveSpeed;
  (map[cor.x][(int)pos.y] == 0) ? pos.x -= dir.x * moveSpeed : 0;
  (map[(int)pos.x][cor.y] == 0) ? pos.y -= dir.y * moveSpeed : 0;
  return (pos);
}

t_window	right(t_window W)
{
  float oldDirX = W.dir.x;
  float oldPlaneX = W.plane.x;

  W.dir.x = W.dir.x * cos(W.rotSpeed) - W.dir.y * sin(W.rotSpeed);
  W.dir.y = oldDirX * sin(W.rotSpeed) + W.dir.y * cos(W.rotSpeed);
  W.plane.x = W.plane.x * cos(W.rotSpeed) - W.plane.y * sin(W.rotSpeed);
  W.plane.y = oldPlaneX * sin(W.rotSpeed) + W.plane.y * cos(W.rotSpeed);
  return (W);
}

t_window	left(t_window W)
{
  float oldDirX = W.dir.x;
  float oldPlaneX = W.plane.x;

  W.dir.x = W.dir.x * cos(-W.rotSpeed) - W.dir.y * sin(-W.rotSpeed);
  W.dir.y = oldDirX * sin(-W.rotSpeed) + W.dir.y * cos(-W.rotSpeed);
  W.plane.x = W.plane.x * cos(-W.rotSpeed) - W.plane.y * sin(-W.rotSpeed);
  W.plane.y = oldPlaneX * sin(-W.rotSpeed) + W.plane.y * cos(-W.rotSpeed);
  return (W);
}
