/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:32:28 by snarain           #+#    #+#             */
/*   Updated: 2021/09/17 19:32:30 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_mlx *d)
{
	if (d->map.tab[d->posp.y - 1][d->posp.x] != '1')
	{
		d->posp.y--;
		d->moves++;
		printf("MOVES = %d\n", d->moves);
	}
	d->posp.move = UP;
}

void	down(t_mlx *d)
{
	if (d->map.tab[d->posp.y + 1][d->posp.x] != '1')
	{
		d->posp.y++;
		d->moves++;
		printf("MOVES = %d\n", d->moves);
	}
	d->posp.move = DOWN;
}

void	right(t_mlx *d)
{
	if (d->map.tab[d->posp.y][d->posp.x + 1] != '1')
	{
		d->posp.x++;
		d->moves++;
		printf("MOVES = %d\n", d->moves);
	}
	d->posp.move = RIGHT;
}

void	left(t_mlx *d)
{
	if (d->map.tab[d->posp.y][d->posp.x - 1] != '1')
	{
		d->posp.x--;
		d->moves++;
		printf("MOVES = %d\n", d->moves);
	}
	d->posp.move = LEFT;
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
	if (d->map.tab[d->posp.y][d->posp.x] == 'C')
	{
		d->map.tab[d->posp.y][d->posp.x] = '0';
		d->item--;
	}
	if (d->map.tab[d->posp.y][d->posp.x] == 'E'
		&& d->item == 0)
	{
		printf("YOU WIN !\n");
		ft_free(d);
	}
	return (1);
}
