/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 18:36:10 by rdidier           #+#    #+#             */
/*   Updated: 2016/04/01 17:13:28 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int					listener(int keycode, void *data)
{
	t_wolfd		*d;

	d = (t_wolfd*)data;
	if (keycode == 53)
	{
		mlx_destroy_window(d->ptr, d->win);
		mlx_destroy_image(d->ptr, d->img->self);
		exit(0);
	}
	if (keycode == 124)
		d->code[0] = !d->code[0];
	else if (keycode == 123)
		d->code[1] = !d->code[1];
	else if (keycode == 126)
		d->code[2] = !d->code[2];
	else if (keycode == 125)
		d->code[3] = !d->code[3];
	return (1);
}

static t_wolfd		*data_init(void)
{
	t_wolfd	*d;

	d = (t_wolfd*)malloc(sizeof(t_wolfd));
	d->ptr = mlx_init();
	d->win = mlx_new_window(d->ptr, WINDOW_W, WINDOW_H,
			"Wolf3d by Mathiisss");
	d->img = (t_img*)malloc(sizeof(t_img));
	d->img->self = mlx_new_image(d->ptr, WINDOW_W, WINDOW_H);
	d->img->buff = mlx_get_data_addr(d->img->self, &d->img->bpp,
			&d->img->bpl, &d->img->endian);
	d->player = new_player(new_point(10, 12), new_point(-1, 0),
			new_point(0, 0.66));
	d->ground = new_color(42, 42, 42);
	d->sky = new_color(142, 142, 255);
	d->east = new_color(0, 125, 125);
	d->west = new_color(255, 125, 125);
	d->north = new_color(125, 0, 125);
	d->south = new_color(125, 125, 0);
	d->ray = new_ray();
	return (d);
}

int					launch_it(char *argv)
{
	t_wolfd	*data;

	data = data_init();
	if (!data)
		return (0);
	if (!read_it(argv, data))
		return (0);
	mlx_do_key_autorepeatoff(data->ptr);
	mlx_loop_hook(data->ptr, loop, data);
	mlx_hook(data->win, KEY_EVENT, KEY_MASK, listener, data);
	mlx_key_hook(data->win, listener, data);
	mlx_loop(data->ptr);
	return (1);
}

int					loop(t_wolfd *d)
{
	move(d->code, d);
	turn(d->code, d, d->player->dir->x, d->player->plane->x);
	algo(d);
	mlx_put_image_to_window(d->ptr, d->win, d->img->self, 0, 0);
	return (1);
}
