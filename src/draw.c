/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:23:55 by snarain           #+#    #+#             */
/*   Updated: 2021/09/16 19:27:54 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player_sprite(t_mlx *d, t_img *tile)
{
	int	x_sc;
	int	y_sc;

	x_sc = (float)d->pos.x_s * ((float)tile->width / (float)BLOCK);
	y_sc = (float)d->pos.y_s * ((float)tile->length / (float)BLOCK);
	if (tile->addr[(x_sc * tile->bpp >> 3) + (y_sc * tile->line)] == 0
		&& tile->addr[(x_sc * tile->bpp >> 3) + 1 + (y_sc * tile->line)] == 0
		&& tile->addr[(x_sc * tile->bpp >> 3) + 2 + (y_sc * tile->line)] == 0)
		return ;
	d->ground.addr[((d->pos.x_s + (d->posP.x * BLOCK)) * d->ground.bpp >> 3)
		+ ((d->pos.y_s + (d->posP.y * BLOCK)) * d->ground.line)]
		= tile->addr[(x_sc * tile->bpp >> 3) + (y_sc * tile->line)];
	d->ground.addr[((d->pos.x_s + (d->posP.x * BLOCK)) * d->ground.bpp >> 3) + 1
		+ ((d->pos.y_s + (d->posP.y * BLOCK)) * d->ground.line)]
		= tile->addr[(x_sc * tile->bpp >> 3) + 1 + (y_sc * tile->line)];
	d->ground.addr[((d->pos.x_s + (d->posP.x * BLOCK)) * d->ground.bpp >> 3) + 2
		+ ((d->pos.y_s + (d->posP.y * BLOCK)) * d->ground.line)]
		= tile->addr[(x_sc * tile->bpp >> 3) + 2 + (y_sc * tile->line)];
}

void ft_loops(t_mlx *d, t_img *tile)
{
	int i;

	i = 0;
	while(i < 1000)
	{
		draw_player_sprite(data, tile);
		mlx_put_image_to_window(data->mlx, data->win, data->ground.img, 0, 0);
		i++;
	}
	while(i < 2000)
	{
		draw_player_sprite(data, tile);
		mlx_put_image_to_window(data->mlx, data->win, data->ground.img, 0, 0);
		i++;
	}
	while(i < 3000)
	{
		draw_player_sprite(data, tile);
		mlx_put_image_to_window(data->mlx, data->win, data->ground.img, 0, 0);
		i++;
	}
}

void	draw_player(t_mlx *data)
{
	data->pos.y_s = 0;
	while (data->pos.y_s < BLOCK)
	{
		data->pos.x_s = 0;
		while (data->pos.x_s < BLOCK)
		{
			if (data->posP.move == LEFT)
				ft_loops(data, &data->Luffy_move)
				//draw_player_sprite(data, &data->Luffy_move);
			else if (data->posP.move == RIGHT)
				draw_player_sprite(data, &data->Luffy_movel);
			else if (data->posP.move == UP)
				draw_player_sprite(data, &data->Luffy_jump);
			else if (data->posP.move == DOWN)
				draw_player_sprite(data, &data->Luffy_jump);
			else
				draw_player_sprite(data, &data->Luffy);
			data->pos.x_s++;
		}
		data->pos.y_s++;
	}
}

void	draw_sprite(t_mlx *d, t_img *tile)
{
	int	x_sc;
	int	y_sc;

	x_sc = (float)d->pos.x_s * ((float)tile->width / (float)BLOCK);
	y_sc = (float)d->pos.y_s * ((float)tile->length / (float)BLOCK);
	if (tile->addr[(x_sc * tile->bpp >> 3) + (y_sc * tile->line)] == 0
		&& tile->addr[(x_sc * tile->bpp >> 3) + 1 + (y_sc * tile->line)] == 0
		&& tile->addr[(x_sc * tile->bpp >> 3) + 2 + (y_sc * tile->line)] == 0)
		return ;
	d->ground.addr[((d->pos.x_s + (d->pos.x * BLOCK)) * d->ground.bpp >> 3)
		+ ((d->pos.y_s + (d->pos.y * BLOCK)) * d->ground.line)]
		= tile->addr[(x_sc * tile->bpp >> 3) + (y_sc * tile->line)];
	d->ground.addr[((d->pos.x_s + (d->pos.x * BLOCK)) * d->ground.bpp >> 3) + 1
		+ ((d->pos.y_s + (d->pos.y * BLOCK)) * d->ground.line)]
		= tile->addr[(x_sc * tile->bpp >> 3) + 1 + (y_sc * tile->line)];
	d->ground.addr[((d->pos.x_s + (d->pos.x * BLOCK)) * d->ground.bpp >> 3) + 2
		+ ((d->pos.y_s + (d->pos.y * BLOCK)) * d->ground.line)]
		= tile->addr[(x_sc * tile->bpp >> 3) + 2 + (y_sc * tile->line)];
}

void	draw_tile(t_mlx *d, t_img *tile)
{
	int	x_sc;
	int	y_sc;

	x_sc = (float)d->pos.x_s * ((float)tile->width / (float)BLOCK);
	y_sc = (float)d->pos.y_s * ((float)tile->length / (float)BLOCK);
	d->ground.addr[((d->pos.x_s + (d->pos.x * BLOCK)) * d->ground.bpp >> 3)
		+ ((d->pos.y_s + (d->pos.y * BLOCK)) * d->ground.line)]
		= tile->addr[(x_sc * tile->bpp >> 3) + (y_sc * tile->line)];
	d->ground.addr[((d->pos.x_s + (d->pos.x * BLOCK)) * d->ground.bpp >> 3) + 1
		+ ((d->pos.y_s + (d->pos.y * BLOCK)) * d->ground.line)]
		= tile->addr[(x_sc * tile->bpp >> 3) + 1 + (y_sc * tile->line)];
	d->ground.addr[((d->pos.x_s + (d->pos.x * BLOCK)) * d->ground.bpp >> 3) + 2
		+ ((d->pos.y_s + (d->pos.y * BLOCK)) * d->ground.line)]
		= tile->addr[(x_sc * tile->bpp >> 3) + 2 + (y_sc * tile->line)];
}
