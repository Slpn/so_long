/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:19:06 by snarain           #+#    #+#             */
/*   Updated: 2021/09/08 21:37:09 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_sprites(t_mlx *d, char tile)
{
	d->pos.y_s = 0;
	while (d->pos.y_s < BLOCK)
	{
		d->pos.x_s = 0;
		while (d->pos.x_s < BLOCK)
		{
			if (tile == 'C')
				draw_sprite(d, &d->fruit);
			else if (tile == 'E' && d->item == 0)
				draw_sprite(d, &d->door_open);
			else if (tile == 'E')
				draw_sprite(d, &d->door);
			d->pos.x_s++;
		}
		d->pos.y_s++;
	}
}

void	draw_tiles(t_mlx *data, char tile)
{
	data->pos.y_s = 0;
	while (data->pos.y_s < BLOCK)
	{
		data->pos.x_s = 0;
		while (data->pos.x_s < BLOCK)
		{
			if (tile == '1')
			{
				if (data->pos.x != 0 && data->pos.y != 0
					&& data->pos.y != (data->map.length - 1)
					&& data->pos.x != (data->map.width - 1))
					draw_tile(data, &data->wall_in);
				else
					draw_tile(data, &data->wall);
			}
			else
				draw_tile(data, &data->grass);
			data->pos.x_s++;
		}
		data->pos.y_s++;
	}
}

int	draw(t_mlx *data)
{
	data->pos.y = 0;
	while (data->pos.y < data->map.length)
	{
		data->pos.x = 0;
		while (data->pos.x < data->map.width)
		{
			draw_tiles(data, data->map.tab[data->pos.y][data->pos.x]);
			if (data->map.tab[data->pos.y][data->pos.x] != 1)
				draw_sprites(data, data->map.tab[data->pos.y][data->pos.x]);
			data->pos.x++;
		}
		data->pos.y++;
	}
	mlx_do_sync(data->mlx);
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->ground.img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	data;

	if (ac == 2)
	{
		data = check_file(av[1]);
		mlx_hook(data.win, 33, 131072, &ft_free, &data);
		mlx_loop_hook(data.mlx, draw, &data);
		mlx_key_hook(data.win, key_hook, &data);
		mlx_do_sync(data.mlx);
		mlx_loop(data.mlx);
	}
	else
		printf("Error \n WRONG ARGUMENNTS NUMBERS !\n");
	return (0);
}
