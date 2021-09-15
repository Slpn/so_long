#include "so_long.h"

void	init_tex(t_mlx *d, t_img *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(d->mlx, path,
			&tex->width, &tex->length);
	if (!tex->img)
	{
		printf("ERROR : %s\n", path);
		ft_free(d);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->line, &tex->endian);
	//*(unsigned int *)tex->addr = 0x0;
	if (!tex->addr)
		ft_free(d);
}

void	init_sprites_and_tiles(t_mlx *d)
{
	init_tex(d, &d->wall, WALL);
	init_tex(d, &d->wall_in, WALL_IN);
	init_tex(d, &d->grass, GRASS);
	init_tex(d, &d->Luffy, LUFFY);
	init_tex(d, &d->Luffy_move, LUFFY_MOVE);
	init_tex(d, &d->Luffy_movel, LUFFY_MOVEL);
	init_tex(d, &d->Luffy_jump, LUFFY_JUMP);
	init_tex(d, &d->fruit, DEMON_FRUIT);
	init_tex(d, &d->door, DOOR);
	init_tex(d, &d->door_open, DOOR_OPEN);
}
