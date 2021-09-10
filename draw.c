#include "../include/so_long.h"

void	draw_player_sprite(t_data *d, t_img *tile)
{
	int x_scale;
	int y_scale;

	x_scale = (float)d->draw.x_s * ((float)tile->width / BLOCK);
	y_scale = (float)d->draw.y_s * ((float)tile->height / BLOCK);
	if (tile->addr[(x_scale * tile->bpp >> 3) + (y_scale * tile->line_length)] == 0
		&& tile->addr[(x_scale * tile->bpp >> 3) + 1 + (y_scale * tile->line_length)] == 0
		&& tile->addr[(x_scale * tile->bpp >> 3) + 2 + (y_scale * tile->line_length)] == 0)
		return ;
	d->display.addr[((d->draw.x_s + (d->pos.x * BLOCK)) //R
			* d->display.bpp >> 3) //width
			+ ((d->draw.y_s + (d->pos.y * BLOCK)) * d->display.line_length)] //height
			= tile->addr[(x_scale * tile->bpp >> 3) + (y_scale * tile->line_length)];
	d->display.addr[((d->draw.x_s + (d->pos.x * BLOCK)) //G
			* d->display.bpp >> 3) + 1 //width
			+ ((d->draw.y_s + (d->pos.y * BLOCK)) * d->display.line_length)] //height
			= tile->addr[(x_scale * tile->bpp >> 3) + 1 + (y_scale * tile->line_length)];
	d->display.addr[((d->draw.x_s + (d->pos.x * BLOCK)) //B
			* d->display.bpp >> 3) + 2 //width
			+ ((d->draw.y_s + (d->pos.y * BLOCK)) * d->display.line_length)] //height
			= tile->addr[(x_scale * tile->bpp >> 3) + 2 + (y_scale * tile->line_length)];
}

void draw_player(t_data *data)
{
	data->draw.y_s = 0;
	while(data->draw.y_s < BLOCK)
	{
		data->draw.x_s = 0;
		while(data->draw.x_s < BLOCK)
		{
			if(data->pos.right)
				draw_player_sprite(data, &data->player);
			else
				draw_player_sprite(data, &data->player_l);
			data->draw.x_s++;
		}
		data->draw.y_s++;
	}
}

void	draw_sprite(t_data *d, t_img *tile)
{
	int x_scale;
	int y_scale;

	x_scale = (float)d->draw.x_s * ((float)tile->width / BLOCK);
	y_scale = (float)d->draw.y_s * ((float)tile->height / BLOCK);
	if (tile->addr[(x_scale * tile->bpp >> 3) + (y_scale * tile->line_length)] == 0
		&& tile->addr[(x_scale * tile->bpp >> 3) + 1 + (y_scale * tile->line_length)] == 0
		&& tile->addr[(x_scale * tile->bpp >> 3) + 2 + (y_scale * tile->line_length)] == 0)
		return ;
	d->display.addr[((d->draw.x_s + (d->draw.x_t * BLOCK)) //R
			* d->display.bpp >> 3) //width
			+ ((d->draw.y_s + (d->draw.y_t * BLOCK)) * d->display.line_length)] //height
			= tile->addr[(x_scale * tile->bpp >> 3) + (y_scale * tile->line_length)];
	d->display.addr[((d->draw.x_s + (d->draw.x_t * BLOCK)) //G
			* d->display.bpp >> 3) + 1 //width
			+ ((d->draw.y_s + (d->draw.y_t * BLOCK)) * d->display.line_length)] //height
			= tile->addr[(x_scale * tile->bpp >> 3) + 1 + (y_scale * tile->line_length)];
	d->display.addr[((d->draw.x_s + (d->draw.x_t * BLOCK)) //B
			* d->display.bpp >> 3) + 2 //width
			+ ((d->draw.y_s + (d->draw.y_t * BLOCK)) * d->display.line_length)] //height
			= tile->addr[(x_scale * tile->bpp >> 3) + 2 + (y_scale * tile->line_length)];
}

void	draw_sprites(t_data *data, int tile)
{
	data->draw.y_s = 0;
	while(data->draw.y_s < BLOCK)
	{
		data->draw.x_s = 0;
		while(data->draw.x_s < BLOCK)
		{
			if(tile == 2)
				draw_sprite(data,&data->cp);
			else if(tile == 4)
				draw_sprite(data,&data->cp_t);
			else if(tile == 3)
				{
					if (data->nb_cp_t < data->nb_cp)
						draw_sprite(data,&data->exit);
					else
						draw_sprite(data,&data->exit_open);
				}
			data->draw.x_s++;
		}
		data->draw.y_s++;
	}
}

void	draw_tile(t_data *d, t_img *tile)
{
	int x_scale;
	int y_scale;

	x_scale = (float)d->draw.x_s * ((float)tile->width / BLOCK);
	y_scale = (float)d->draw.y_s * ((float)tile->height / BLOCK);
	d->display.addr[((d->draw.x_s + (d->draw.x_t * BLOCK)) //R
			* d->display.bpp >> 3) //width
			+ ((d->draw.y_s + (d->draw.y_t * BLOCK)) * d->display.line_length)] //height
			= tile->addr[(x_scale * tile->bpp >> 3) + (y_scale * tile->line_length)];
	d->display.addr[((d->draw.x_s + (d->draw.x_t * BLOCK)) //G
			* d->display.bpp >> 3) + 1 //width
			+ ((d->draw.y_s + (d->draw.y_t * BLOCK)) * d->display.line_length)] //height
			= tile->addr[(x_scale * tile->bpp >> 3) + 1 + (y_scale * tile->line_length)];
	d->display.addr[((d->draw.x_s + (d->draw.x_t * BLOCK)) //B
			* d->display.bpp >> 3) + 2 //width
			+ ((d->draw.y_s + (d->draw.y_t * BLOCK)) * d->display.line_length)] //height
			= tile->addr[(x_scale * tile->bpp >> 3) + 2 + (y_scale * tile->line_length)];
}

void	draw_tiles(t_data *data, int tile)
{
	data->draw.y_s = 0;
	while(data->draw.y_s < BLOCK)
	{
		data->draw.x_s = 0;
		while(data->draw.x_s < BLOCK)
		{
			if(tile == 1)
				draw_tile(data, &data->wall);
			else
				draw_tile(data, &data->path);
			data->draw.x_s++;
		}
		data->draw.y_s++;
	}
}

int	draw(t_data *data)
{

	data->draw.y_t = 0;

	while(data->draw.y_t < data->map_height)
	{
		data->draw.x_t = 0;
		while(data->draw.x_t < data->map_width)
		{
			draw_tiles(data,data->map[data->draw.y_t][data->draw.x_t]);
			// if (data->map[data->draw.y_t][data->draw.x_t] != 1)
				draw_sprites(data, data->map[data->draw.y_t][data->draw.x_t]);
			data->draw.x_t++;
		}
		data->draw.y_t++;
	}
	draw_player(data);

	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
		data->display.img, 0, 0);
	return (0);
}
