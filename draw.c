#include "so_long.h"

void	draw_player_sprite(t_mlx *d, t_img *tile)
{
	int	x_sc;
	int	y_sc;

	x_sc = (float)d->pos.x * ((float)tile->width / BLOCK);
	y_sc = (float)d->pos.y * ((float)tile->height / BLOCK);
	if (tile->addr[(x_sc * tile->bpp >> 3) + (y_sc * tile->length)] == 0
		&& tile->addr[(x_sc * tile->bpp >> 3) + 1 + (y_sc * tile->length)] == 0
		&& tile->addr[(x_sc * tile->bpp >> 3) + 2 + (y_sc * tile->length)] == 0)
		return ;
	d->ground.addr[((d->pos.x + (d->pos.x * BLOCK)) //R
			* d->ground.bpp >> 3) //width
			+ ((d->pos.y + (d->pos.y * BLOCK)) * d->ground.length)] //height
			= tile->addr[(x_sc * tile->bpp >> 3) + (y_sc * tile->length)];
	d->ground.addr[((d->pos.x + (d->pos.x * BLOCK)) //G
			* d->ground.bpp >> 3) + 1 //width
			+ ((d->pos.y + (d->pos.y * BLOCK)) * d->ground.length)] //height
			= tile->addr[(x_sc * tile->bpp >> 3) + 1 + (y_sc * tile->length)];
	d->ground.addr[((d->pos.x + (d->pos.x * BLOCK)) //B
			* d->ground.bpp >> 3) + 2 //width
			+ ((d->pos.y + (d->pos.y * BLOCK)) * d->ground.length)] //height
			= tile->addr[(x_sc * tile->bpp >> 3) + 2 + (y_sc * tile->length)];
}

void draw_player(t_mlx *data)
{
	data->draw.y_s = 0;
	while (data->posP.y < BLOCK)
	{
		data->draw.x_s = 0;
		while (data->draw.x_s < BLOCK)
		{
			if (data->pos.right)
				draw_player_sprite(data, &data->player);
			else
				draw_player_sprite(data, &data->player_l);
			data->draw.x_s++;
		}
		data->draw.y_s++;
	}
}

void	draw_sprite(t_mlx *d, t_img *tile)
{
	int	x_sc;
	int	y_sc;

	x_sc = (float)d->pos.x * ((float)tile->width / BLOCK);
	y_sc = (float)d->pos.y * ((float)tile->height / BLOCK);
	if (tile->addr[(x_sc * tile->bpp >> 3) + (y_sc * tile->length)] == 0
		&& tile->addr[(x_sc * tile->bpp >> 3) + 1 + (y_sc * tile->length)] == 0
		&& tile->addr[(x_sc * tile->bpp >> 3) + 2 + (y_sc * tile->length)] == 0)
		return ;
	d->ground.addr[((d->pos.x + (d->draw.x_t * BLOCK)) //R
			* d->ground.bpp >> 3) //width
			+ ((d->pos.y + (d->draw.y_t * BLOCK)) * d->ground.length)] //height
			= tile->addr[(x_sc * tile->bpp >> 3) + (y_sc * tile->length)];
	d->ground.addr[((d->pos.x + (d->draw.x_t * BLOCK)) //G
			* d->ground.bpp >> 3) + 1 //width
			+ ((d->pos.y + (d->draw.y_t * BLOCK)) * d->ground.length)] //height
			= tile->addr[(x_sc * tile->bpp >> 3) + 1 + (y_sc * tile->length)];
	d->ground.addr[((d->pos.x + (d->draw.x_t * BLOCK)) //B
			* d->ground.bpp >> 3) + 2 //width
			+ ((d->pos.y + (d->draw.y_t * BLOCK)) * d->ground.length)] //height
			= tile->addr[(x_sc * tile->bpp >> 3) + 2 + (y_sc * tile->length)];
}

void	draw_sprites(t_mlx *d, char tile)
{
	d->draw.y_s = 0;
	while (d->draw.y_s < TILE_SIZE)
	{
		d->draw.x_s = 0;
		while (d->draw.x_s < TILE_SIZE)
		{
			if (tile == 'C')
				draw_sprite(d, &d->fruit);
			d->draw.x_s++;
		}
		d->draw.y_s++;
	}
}

void	draw_tile(t_mlx *d, t_img *tile)
{
	int	x_sc;
	int	y_sc;

	x_sc = (float)d->pos.x * ((float)tile->width / BLOCK);
	y_sc = (float)d->pos.y * ((float)tile->height / BLOCK);
	d->ground.addr[((d->pos.x + (d->draw.x_t * BLOCK)) //R
			* d->ground.bpp >> 3) //width
			+ ((d->pos.y + (d->draw.y_t * BLOCK)) * d->ground.length)] //height
			= tile->addr[(x_sc * tile->bpp >> 3) + (y_sc * tile->length)];
	d->ground.addr[((d->pos.x + (d->draw.x_t * BLOCK)) //G
			* d->ground.bpp >> 3) + 1 //width
			+ ((d->pos.y + (d->draw.y_t * BLOCK)) * d->ground.length)] //height
			= tile->addr[(x_sc * tile->bpp >> 3) + 1 + (y_sc * tile->length)];
	d->ground.addr[((d->pos.x + (d->draw.x_t * BLOCK)) //B
			* d->ground.bpp >> 3) + 2 //width
			+ ((d->pos.y + (d->draw.y_t * BLOCK)) * d->ground.length)] //height
			= tile->addr[(x_sc * tile->bpp >> 3) + 2 + (y_sc * tile->length)];
}

void	draw_tiles(t_mlx *data, char tile)
{
	data->draw.y_s = 0;
	while (data->draw.y_s < BLOCK)
	{
		data->draw.x_s = 0;
		while (data->draw.x_s < BLOCK)
		{
			if (tile == '1')
				draw_tile(data, &data->img_wall);
			else
				draw_tile(data, &data->path);
			data->draw.x_s++;
		}
		data->draw.y_s++;
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
			draw_tiles(data,data->map.tab[data->pos.y][data->pos.x]);
			// if (data->map.tab[data->pos.y][data->pos.x] != 1)
			draw_sprites(data, data->map.tab[data->pos.y][data->pos.x]);
			data->pos.x++;
		}
		data->pos.y++;
	}
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->ground.img, 0, 0);
	return (0);
}
