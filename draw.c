#include "so_long.h"

void	draw_player_sprite(t_mlx *d, t_img *tile)
{
	int	x_sc;
	int	y_sc;

	x_sc = (float)d->pos.x_s * ((float)tile->width / (float)BLOCK);
	y_sc = (float)d->pos.y_s * ((float)tile->length / (float)BLOCK);
	// if (tile->addr[(x_sc * tile->bpp >> 3) + (y_sc * tile->line)] == 0
	// 	&& tile->addr[(x_sc * tile->bpp >> 3) + 1 + (y_sc * tile->line)] == 0
	// 	&& tile->addr[(x_sc * tile->bpp >> 3) + 2 + (y_sc * tile->line)] == 0)
	// 	return ;
		d->ground.addr[((d->pos.x_s + (d->posP.x * BLOCK)) * d->ground.bpp >> 3) //width
				+ ((d->pos.y_s + (d->posP.y * BLOCK)) * d->ground.line)] //length
				= tile->addr[(x_sc * tile->bpp >> 3) + (y_sc * tile->line)];
		d->ground.addr[((d->pos.x_s + (d->posP.x * BLOCK)) * d->ground.bpp >> 3) + 1 //width
				+ ((d->pos.y_s + (d->posP.y * BLOCK)) * d->ground.line)] //length
				= tile->addr[(x_sc * tile->bpp >> 3) + 1 + (y_sc * tile->line)];
		d->ground.addr[((d->pos.x_s + (d->posP.x * BLOCK)) * d->ground.bpp >> 3) + 2 //width
				+ ((d->pos.y_s + (d->posP.y * BLOCK)) * d->ground.line)] //length
				= tile->addr[(x_sc * tile->bpp >> 3) + 2 + (y_sc * tile->line)];
}

void draw_player(t_mlx *data)
{
	data->pos.y_s = 0;
	while (data->pos.y_s < BLOCK)
	{
		data->pos.x_s = 0;
		while (data->pos.x_s < BLOCK)
		{
			// if (data->pos.move == RIGHT)
				draw_player_sprite(data, &data->Luffy);
			// else
			// 	draw_player_sprite(data, &data->Luffy_move);
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
	if (tile->addr[(x_sc * tile->bpp >> 3) + (y_sc * tile->length)] == 0
		&& tile->addr[(x_sc * tile->bpp >> 3) + 1 + (y_sc * tile->length)] == 0
		&& tile->addr[(x_sc * tile->bpp >> 3) + 2 + (y_sc * tile->length)] == 0)
		return ;
		d->ground.addr[((d->pos.x_s + (d->pos.x * BLOCK)) * d->ground.bpp >> 3) //width
				+ ((d->pos.y_s + (d->pos.y * BLOCK)) * d->ground.line)] //length
				= tile->addr[(x_sc * tile->bpp >> 3) + (y_sc * tile->line)];
		d->ground.addr[((d->pos.x_s + (d->pos.x * BLOCK)) * d->ground.bpp >> 3) + 1 //width
				+ ((d->pos.y_s + (d->pos.y * BLOCK)) * d->ground.line)] //length
				= tile->addr[(x_sc * tile->bpp >> 3) + 1 + (y_sc * tile->line)];
		d->ground.addr[((d->pos.x_s + (d->pos.x * BLOCK)) * d->ground.bpp >> 3) + 2 //width
				+ ((d->pos.y_s + (d->pos.y * BLOCK)) * d->ground.line)] //length
				= tile->addr[(x_sc * tile->bpp >> 3) + 2 + (y_sc * tile->line)];
}

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
			d->pos.x_s++;
		}
		d->pos.y_s++;
	}
}

void	draw_tile(t_mlx *d, t_img *tile)
{
	int	x_sc;
	int	y_sc;

	x_sc = (float)d->pos.x_s * ((float)tile->width / (float)BLOCK);
	y_sc = (float)d->pos.y_s * ((float)tile->length / (float)BLOCK);

	d->ground.addr[((d->pos.x_s + (d->pos.x * BLOCK)) * d->ground.bpp >> 3) //width
			+ ((d->pos.y_s + (d->pos.y * BLOCK)) * d->ground.line)] //length
			= tile->addr[(x_sc * tile->bpp >> 3) + (y_sc * tile->line)];
	d->ground.addr[((d->pos.x_s + (d->pos.x * BLOCK)) * d->ground.bpp >> 3) + 1 //width
			+ ((d->pos.y_s + (d->pos.y * BLOCK)) * d->ground.line)] //length
			= tile->addr[(x_sc * tile->bpp >> 3) + 1 + (y_sc * tile->line)];
	d->ground.addr[((d->pos.x_s + (d->pos.x * BLOCK)) * d->ground.bpp >> 3) + 2 //width
			+ ((d->pos.y_s + (d->pos.y * BLOCK)) * d->ground.line)] //length
			= tile->addr[(x_sc * tile->bpp >> 3) + 2 + (y_sc * tile->line)];
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
				draw_tile(data, &data->wall_in);
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
	while(data->pos.y < data->map.length)
	{
		data->pos.x = 0;
		while(data->pos.x < data->map.width)
		{
			draw_tiles(data, data->map.tab[data->pos.y][data->pos.x]);
				// if (data->map.tab[data->pos.y][data->pos.x] != 1)
				// 	draw_sprites(data, data->map.tab[data->pos.y][data->pos.x]);
			data->pos.x++;
		}
		data->pos.y++;
	}
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->ground.img, 0, 0);
	return (0);
}
