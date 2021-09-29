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
	d->ground.addr[((d->pos.x_s + (d->posp.x * BLOCK)) * d->ground.bpp >> 3)
		+ ((d->pos.y_s + (d->posp.y * BLOCK)) * d->ground.line)]
		= tile->addr[(x_sc * tile->bpp >> 3) + (y_sc * tile->line)];
	d->ground.addr[((d->pos.x_s + (d->posp.x * BLOCK)) * d->ground.bpp >> 3) + 1
		+ ((d->pos.y_s + (d->posp.y * BLOCK)) * d->ground.line)]
		= tile->addr[(x_sc * tile->bpp >> 3) + 1 + (y_sc * tile->line)];
	d->ground.addr[((d->pos.x_s + (d->posp.x * BLOCK)) * d->ground.bpp >> 3) + 2
		+ ((d->pos.y_s + (d->posp.y * BLOCK)) * d->ground.line)]
		= tile->addr[(x_sc * tile->bpp >> 3) + 2 + (y_sc * tile->line)];
}

void	draw_player(t_mlx *data)
{
	data->pos.y_s = 0;
	while (data->pos.y_s < BLOCK)
	{
		data->pos.x_s = 0;
		while (data->pos.x_s < BLOCK)
		{
			if (data->posp.move == LEFT)
				draw_player_sprite(data, &data->luffy_move);
			else if (data->posp.move == RIGHT)
				draw_player_sprite(data, &data->luffy_movel);
			else if (data->posp.move == UP)
				draw_player_sprite(data, &data->luffy_jump);
			else if (data->posp.move == DOWN)
				draw_player_sprite(data, &data->luffy_jump);
			else if (data->posp.move == STRAIGHT)
				draw_player_sprite(data, &data->luffy);
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
