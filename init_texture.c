/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:12:44 by snarain           #+#    #+#             */
/*   Updated: 2021/09/08 21:39:55 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_block(t_mlx *data, char *path, int pos, int y)
{

	data->img_wall.img = mlx_xpm_file_to_image(data->mlx, path, 
			&data->width, &data->length);
	if (!data->img_wall.img)
	{
		printf("CAN'T OPEN XPM");
		ft_free(data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img_wall.img, 
			pos, (y * BLOCK));
}
void	render(t_mlx *data, int pos, int x, int y)
{
	if (y == 0 && x == 0)
		put_block(data, WALL_LUP, pos, y);
	else if (y == 0 && x == (data->map.width - 1))
		put_block(data, WALL_RUP, pos, y);
	else if (y == (data->map.length - 1) && x == 0)
		put_block(data, WALL_LDOWN, pos, y);
	else if ((y == (data->map.length - 1)) && (x == (data->map.width - 1)))
		put_block(data, WALL_RDOWN, pos, y);
	else if (y == 0 && (x != 0 || x != (data->map.width -1)))
		put_block(data, WALL_UP, pos, y);
	else if (y == (data->map.length - 1) && (x != 0 || x != (data->map.width -1)))
		put_block(data, WALL_DOWN, pos, y);
	else
		put_block(data, GRASS, pos, y);
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
				render(data, pos, x, y);
			if (data->map.tab[y][x] == '0')
				put_block(data, GRASS, pos, y);
			if (data->map.tab[y][x] == 'C')
				put_block(data, DEMON_FRUIT, pos, y);
			pos += BLOCK;
			x++;
		}
		y++;
	}
}

int	init_mlx(t_mlx *data)
{
	data->win_width = (data->map.width * BLOCK);
	data->win_length = (data->map.length * BLOCK);
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
