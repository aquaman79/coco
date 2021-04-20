/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquamar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 10:15:46 by aquamar           #+#    #+#             */
/*   Updated: 2021/03/30 10:15:54 by aquamar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

# define BACK_S_S		115
# define RIGHT_D_D		100
# define LEFT_A_Q		97
#include <math.h>
#define Pi1 3.14159265358979323846 
#include <mlx.h> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#define COL 15 
#define LIN 25
#define TAIL 32
#define X LIN*TAIL
#define Y COL *TAIL
#define left 65361
#define right 65363
#define down 65364
#define up 65362
#define rotr 100
#define rotl 97

# define MLX_TYPE_SHM_PIXMAP 3
# define MLX_TYPE_SHM 2

int tailx = 800/25;
int taily = 480/15;
float FOV= 1.0472 ;
int px = 800/2;
int py = 480/2;
//float rotation = M_PI;

struct player{
int ver;
int hori ;
float angle;
};
float rotation = M_PI/2;

typedef struct s_data {
    void        *img;
    char        *addr; 
    int         bits_per_pixel; 
    int         line_length;
    int         endian;
}               t_data;

struct mywin
{
    void        *mlx;
    void        *win;
    int         map[15][25];
    t_data      img;
    struct player play ;        
};

void            my_mlx_pixel_put(t_data *data, int x, int y, int color);
void        drawcube(struct mywin win, int x , int y,int color );
void         reykey_hook(struct mywin *new);
int             key_hook(int keycode, struct mywin *new);
void        draw(struct mywin *new);
void    update(struct mywin *new , int *px,int *py);
void    creati (struct mywin *new);
int drawc(struct mywin *new);
void dda(int x1, int y1, int x2, int y2, t_data *img);

#endif

