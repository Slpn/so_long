#include "so_long.h"

void	up(t_mlx *d)
{
	if (d->map.tab[d->posP.y - 1][d->posP.x] != '1')
	{
		d->posP.y--;
		d->moves++;
		printf("MOVES = %d\n", d->moves);
	}
	d->posP.move = UP;
}

void	down(t_mlx *d)
{
	if (d->map.tab[d->posP.y + 1][d->posP.x] != '1')
	{
		d->posP.y++;
		d->moves++;
		printf("MOVES = %d\n", d->moves);
	}
	d->posP.move = DOWN;
}

void	right(t_mlx *d)
{
	if (d->map.tab[d->posP.y][d->posP.x + 1] != '1')
	{
		d->posP.x++;
		d->moves++;
		printf("MOVES = %d\n", d->moves);
	}
	d->posP.move = RIGHT;
}

void	left(t_mlx *d)
{
	if (d->map.tab[d->posP.y][d->posP.x - 1] != '1')
	{
		d->posP.x--;
		d->moves++;
		printf("MOVES = %d\n", d->moves);
	}
	d->posP.move = LEFT;
}

int	key_hook(int key, t_mlx *d)
{
	if (key == ESC)
		ft_free(d);
	else if (key == W)
		up(d);
	else if (key == S)
		down(d);
	else if (key == D)
		right(d);
	else if (key == A)
		left(d);
	if (d->map.tab[d->posP.y][d->posP.x] == 'C')
	{
		d->map.tab[d->posP.y][d->posP.x] = '0';
		d->item--;
	}
	if (d->map.tab[d->posP.y][d->posP.x] == 'E'
		&& d->item == 0)
	{
		printf("WIN\n");
		ft_free(d);
	}
	return (1);
}
