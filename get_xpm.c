#include "so_long.h"

void	init_tex(t_mlx *d, t_img *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(d->mlx, path,
			&tex->width, &tex->length);
	if (!tex->img)
	{
		printf("ERROR : %s\n", path);
		exit(0);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->length, &tex->endian);
	if (!tex->addr)
		exit(0);
}

/*void	init_exit_tex(t_mlx *d)
{
	init_tex(d, &d->exit_close, EXIT_CLOSE);
	init_tex(d, &d->exit_open[0], EXIT_OPEN0);
	init_tex(d, &d->exit_open[1], EXIT_OPEN1);
	init_tex(d, &d->exit_open[2], EXIT_OPEN2);
	init_tex(d, &d->exit_open[3], EXIT_OPEN3);
	init_tex(d, &d->exit_open[4], EXIT_OPEN4);
	init_tex(d, &d->exit_open[5], EXIT_OPEN5);
	init_tex(d, &d->exit_open[6], EXIT_OPEN6);
	init_tex(d, &d->exit_open[7], EXIT_OPEN7);
	init_tex(d, &d->exit_open[8], EXIT_OPEN8);
	init_tex(d, &d->exit_open[9], EXIT_OPEN9);
	init_tex(d, &d->exit_open[10], EXIT_OPEN10);
	init_tex(d, &d->exit_open[11], EXIT_OPEN11);
	init_tex(d, &d->exit_open[12], EXIT_OPEN12);
	init_tex(d, &d->exit_open[13], EXIT_OPEN13);
}*/

void	init_sprites_and_tiles(t_mlx *d)
{
	init_tex(d, &d->wall, WALL);
	init_tex(d, &d->wall_in, WALL_IN);
	init_tex(d, &d->grass, GRASS);
	init_tex(d, &d->Luffy, LUFFY);
	init_tex(d, &d->Luffy_move, LUFFY);
	init_tex(d, &d->Luffy_jump, LUFFY);
	init_tex(d, &d->fruit, DEMON_FRUIT);
}
