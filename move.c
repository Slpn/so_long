#include "so_long.h"

void	up(t_mlx *d)
{
	if (d->map.tab[d->posP.y - 1][d->posP.x] != '1')
	{
		d->posP.y--;
		d->moves++;
	}
	//d->player.dir = UP;
}

void	down(t_mlx *d)
{
	if (d->map.tab[d->posP.y + 1][d->posP.x] != '1')
	{
		d->posP.y++;
		d->moves++;
	}
	//d->player.dir = DOWN;
}

void	right(t_mlx *d)
{
	if (d->map.tab[d->posP.y][d->posP.x + 1] != '1')
	{
		d->posP.x++;
		d->moves++;
	}
	//d->player.dir = RIGHT;
}

void	left(t_mlx *d)
{
	if (d->map.tab[d->posP.y][d->posP.x - 1] != '1')
	{
		d->posP.x--;
		d->moves++;
	}
	//d->player.dir = LEFT;
}

int	key_hook(int key, t_mlx *d)
{
	if (key == ESC)
		exit_game(d);
	else if (key == W)
		up(d);
	else if (key == S)
		down(d);
	else if (key == D)
		right(d);
	else if (key == A)
		left(d);
	printf("MOVES = %d\n", d->moves);
	if (d->map.tab[d->posP.y][d->posP.x] == 'E'
		&& d->item == 0)
	{
		printf("WIN\n");
		exit(0);
	}
	return (1);
}
