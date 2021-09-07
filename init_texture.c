/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:12:44 by snarain           #+#    #+#             */
/*   Updated: 2021/09/07 21:11:58 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_text(t_mlx *data, int x, int y, int pos)
{
	if (data->map.tab[y][x] == '0')
	{
		data->img_wall.img = mlx_xpm_file_to_image(data->mlx, GRASS, 
				&data->width, &data->length);
		mlx_put_image_to_window(data->mlx, data->win, data->img_wall.img, 
				pos, (y * BLOCK));
	}
	if (data->map.tab[y][x] == 'C')
	{
		data->img_wall.img = mlx_xpm_file_to_image(data->mlx, DEMON_FRUIT,
				&data->width, &data->length);
		mlx_put_image_to_window(data->mlx, data->win, data->img_wall.img, 
				pos, (y * BLOCK));
	}
}

void	init_map(t_mlx *data)
{
	int	x;
	int	y;
	int	pos;

	x = 0;
	y = 0;
	pos = 0;
	mlx_new_image(data->mlx, data->win_width, data->win_length);
	while (y < data->map.length)
	{
		x = 0;
		pos = 0;
		while (x < data->map.width)
		{
			if (data->map.tab[y][x] == '1')
			{
				data->img_wall.img = mlx_xpm_file_to_image(data->mlx, WALL, 
						&data->width, &data->length);
				mlx_put_image_to_window(data->mlx, data->win, data->img_wall.img, 
						pos, (y * BLOCK));
			}
			else
				check_text(data, x, y, pos);
			pos += BLOCK;
			x++;
		}
		y++;
	}
}

void	window_reso(t_mlx *data)
{
	data->win_width = (data->map.width * BLOCK);
	data->win_length = (data->map.length * BLOCK);
}

int	init_mlx(t_mlx *data)
{
	window_reso(data);
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_free(data);
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_length,
			"so_long");
	if (!data->win)
		ft_free(data);
	init_map(data);
	return (0);
}
