/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 18:36:10 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/27 21:39:52 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

//TEMp
void				print_map(int **map, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putnbr(map[i][j]);
			ft_putstr(" ");
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
//TEMp


static void			print_cam(t_wolfd *data)
{
	mlx_string_put(data->ptr, data->win, 0, 0, 16777215,
			"Afficher des trucs ?");
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
	return (d);
}

int					launch_it(char *argv)
{
	t_wolfd	*data;

	data = data_init();
	if (!data)
		return (0);
	mlx_put_image_to_window(data->ptr, data->win, data->img->self, 0, 0);
	print_cam(data);
	if (!read_it(argv, data))
		return (0);
	print_map(data->map, data->size_map);
	//mlx_key_hook(data->win, listener, (void*)data);
	//mlx_hook(data->win, 6, (1L << 6), mouse_moove, (void*)data);
	//mlx_mouse_hook(data->win, mouse_click, (void*)data);
	//mlx_loop(data->ptr);
	return (1);
}