/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquamar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 09:53:54 by aquamar           #+#    #+#             */
/*   Updated: 2021/03/30 09:53:57 by aquamar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <mlx.h>
#include <math.h>
#include <stdlib.h>

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void drawcube(struct mywin win, int x, int y, int color)
{
    int max_x;
    int max_y;

    max_x = x + tailx;
    max_y = y + taily;

    while (x < (max_x))
    {

        y = max_y - taily;
        while (y < (max_y))
        {
            my_mlx_pixel_put(&win.img, x, y, color);
            y++;
        }
        x++;
    }
}
/*void drawline(struct mywin *new,int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;
 
	dx=x1-x0;
	dy=y1-y0;
 
	x=x0;
	y=y0;
 
	p=2*dy-dx;
 
	while(x<x1 || y <y1)
	{
		if(p>=0)
		{
			my_mlx_pixel_put(&new->img,x,y,1783434);
			y=y+1;
			p=p+2*dy-2*dx;
		}
		else
		{
			my_mlx_pixel_put(&new->img,x,y,1783434);
			p=p+2*dy;
		}
		x=x+1;
	}
}*/
void dda(int x1, int y1, int x2, int y2, t_data *img)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    float xinc, yinx;
    int steps;
    int i = 0;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    xinc = dx / (float)steps;
    yinx = dy / (float)steps;

    float x = x1;
    float y = y1;
    while (i <= steps)
    {
        my_mlx_pixel_put(img, round(x), round(y), 0x000000FF);
        x += xinc;
        y += yinx;
        i++;
    }
}
void draw_line(int a, int b, float angle, int d, t_data *img)
{
    int i;
    int c;

    c = 1703425;
    i = 0;
    if (d == 0)
        d = 50;
    while (i <= d)
    {
        a = (px) + cos(angle) * i;
        b = (py) + sin(angle) * i;
        my_mlx_pixel_put(img, a, b, c);
        i++;
    }

    a = (px) + cos(angle) * 55;
    b = (py) + sin(angle) * 55;
    my_mlx_pixel_put(img, a, b, c + 210);
}

void draw_circle(struct mywin *new, int px, int py, int d)
{

    int r = d / 2;
    //int m = r;
    int t = 0; //degree from 0 to 360
    int x = (px + (r * cos(t * M_PI / 180)));
    int y = (py + (r * sin(t * M_PI / 180)));

    int ox = px, oy = py; // origin

    for (int x = -r; x < r; x++)
    {
        int height = (int)sqrt(r * r - x * x);

        for (int y = -height; y < height; y++)
            my_mlx_pixel_put(&new->img, x + ox, y + oy, 0x0FF0000);
    }
}
void draw_the_player(struct mywin *new, int px, int py)
{
    int d = 20;
    int l = 50;
    draw_circle(new, px, py, d);
    float angle = 90 * M_PI / 180;
    //dda(px, py, px + cos(angle) * l, py + sin(angle) * l, &new->img);

    /// the wrong lin!e
    //  draw_line(px, py, angle, l, &new->img);

    //// the right line
    draw_line(px, py,rotation, l, &new->img);

  //  draw_line(px, py, 180 * M_PI / 180, l, &new->img);
}

void reykey_hook(struct mywin *new)
{
    new->play.hori = 0;
    new->play.hori = 0;
    new->play.ver = 0;
    new->play.ver = 0;
   //*rotation = 1;
}

int key_hook(int keycode, struct mywin *new)
{

    if (keycode == left)
        new->play.ver = -1;
    else if (keycode == right)
        new->play.ver = +1;
    else
        new->play.ver = 0;

    if (keycode == up)
        new->play.hori = -1;
    else if (keycode == down)
        new->play.hori = +1;
    else
        new->play.hori = 0;
   // printf("Hello from key_hook!\n");
    //printf("%d \n",new->play.ver);
 //   printf("cou %d cou", keycode);
    return 0;
}

void draw(struct mywin *new)
{
    int i;
    int j;
    j = 0;
    while (j < 15)
    {
        i = 0;
        while (i < 25)
        {
            if (new->map[j][i] == 1)
                drawcube(*new, i * tailx, j * taily, 255255240);
            i++;
        }
        j++;
    }
}
void update(struct mywin *new, int *px, int *py, float *rotation)
{

    *px = *px + new->play.ver;
    *py = *py + new->play.hori;
    if (new->play.ver == -1 )
    {
     //   *rotation = 2*(*rotation *-1 );
            *rotation = M_PI *-1;
            if(*rotation >0)
                *rotation = (*rotation *-1 );
    }
    if ((new->play.ver == 1 && *rotation <0)) 
    {
        *rotation = 2*M_PI * -1  ;
        if(*rotation <0)
              * rotation = (*rotation *-1 );
    }
    if(new->play.hori==1)
    {
       * rotation=M_PI/2;
    }
            printf(" btata %f \n",*rotation);
      reykey_hook(new);
  // * rotation = M_PI;

}
void creati(struct mywin *new)
{
    new->img.img = mlx_new_image(new->mlx, 1000, 400);
    new->img.addr = mlx_get_data_addr(new->img.img, &new->img.bits_per_pixel, &new->img.line_length,
                                      &new->img.endian);
}
int drawc(struct mywin *new)
{
    draw(new);

    draw_the_player(new, px, py);
    mlx_put_image_to_window(new->mlx,
     new->win, new->img.img, 0, 0);
    if (!(new->play.ver) || !(new->play.hori))
    {
        creati(new);
        draw(new);
        update(new, &px, &py, &rotation);
        draw_the_player(new, px, py);
        mlx_put_image_to_window(new->mlx, new->win, new->img.img, 0, 0);
    }
    return 0;
}

int main()
{
    int map[25][25] =
        {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1},
            {1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1},
            {1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        };
    struct mywin new;
    new.mlx = mlx_init();
    new.win = mlx_new_window(new.mlx, 1000, 400, "hello");
    memcpy(new.map, map, sizeof(int) * 25 * 15);
    creati(&new);

    mlx_hook(new.win, 2, 1L << 0, key_hook, &new);

    mlx_loop_hook(new.mlx, drawc, &new);

    mlx_loop(new.mlx);
}