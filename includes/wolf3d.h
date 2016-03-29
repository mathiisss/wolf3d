/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 18:33:07 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/29 20:38:14 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRACTOL_H
# define __FRACTOL_H

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"
# include <mlx.h>

//TEMP
# include <stdio.h>
//TEMP

# define SEPARATOR		','
# define WINDOW_H 		768
# define WINDOW_W	 	1024
# define ROTSPEED		0.1

typedef unsigned char	t_uchar;

typedef struct		s_color
{
	t_uchar			r;
	t_uchar			g;
	t_uchar			b;
}					t_color;

typedef struct		s_img
{
	void			*self;
	char			*buff;
	int				bpp;
	int				bpl;
	int				endian;
}					t_img;

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct		s_player
{
	t_point			*pos;
	t_point			*dir;
	t_point			*plane;
}					t_player;

typedef struct		s_wolfd
{
	t_color			*black;
	t_player		*player;
	int				size_map;
	//int				nbrw;
	int				**map;
	void			*ptr;
	void			*win;
	t_img			*img;
}					t_wolfd;

int					listener(int keycode, void *d);

void				super_main(t_wolfd *d);

int					pix_on_img(t_img *img, int x, int y, t_color *clr);
void				draw_vline(t_wolfd *d, int x, int len, int type);

int					launch_it(char *argv);
int					read_it(char *file_name, t_wolfd *d);

t_point				*new_point(double x, double y);
t_color				*new_color(t_uchar r, t_uchar g, t_uchar b);
t_player			*new_player(t_point *pos, t_point *dir, t_point *plane);
#endif
