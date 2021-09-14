/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:12:44 by snarain           #+#    #+#             */
/*   Updated: 2021/09/09 19:39:17 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_ground(t_mlx *d)
{
	d->ground.img = mlx_new_image(d->mlx, d->win_width, d->win_length);
	d->ground.addr = mlx_get_data_addr(d->ground.img,
			&d->ground.bpp, &d->ground.line, &d->ground.endian);
	if (!d->ground.img || !d->ground.addr)
		exit(0);
	//d->ground_load = true;
}

void	init_mlx(t_mlx *data)
{
	data->win_width = (data->map.width * BLOCK);
	data->win_length = (data->map.length * BLOCK);
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(0);
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_length,
			"so_long");
	if (!data->win)
		exit(0);
	init_ground(data);
	init_sprites_and_tiles(data);
}
