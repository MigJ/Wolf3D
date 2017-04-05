/*
** mylist.h for  in /home/joubert/delivery/wolf3d
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Jan  3 14:46:02 2017 Joubert Miguel
** Last update Sun Jan 15 18:52:47 2017 Joubert Miguel
*/

typedef struct s_file
{
  int   fd;
  int   size;
  int   i;
  int   j;
  int   k;
  char  c;
  char  *buffer;
}t_file;

typedef  struct s_my_framebuffer
{
  sfUint8 *pixels;
  int width ;
  int height;
}t_my_framebuffer;

typedef  struct s_draw_line
{
  int   i;
  int   xinc;
  int   yinc;
  int   cumul;
}t_draw_line;

typedef struct s_window
{
  sfTexture *texture;
  sfEvent       event;
  sfVector2f    pos;
  sfVector2f    dir;
  sfVector2f    plane;
  float time;
  float oldTime;
  float frameTime;
  float moveSpeed;
  float rotSpeed;
  float perpWallDist;
  float x;
  int   **map;
  int   mexit;
}t_window;


typedef struct s_raycast
{
  float cameraX;
  float perpWallDist;
  sfVector2f ray_dir;
  sfVector2i map_co;
  sfVector2f side_dist;
  sfVector2f delta;
  sfVector2i step;
  int hit;
  int side;
}t_raycast;
