/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 20:27:33 by snarain           #+#    #+#             */
/*   Updated: 2021/09/06 21:28:40 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_map(t_mlx *data)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	while (data->map.tab[y][x])
	{
		if (data->map.tab[y][x] == '1')
		{
			x++;
		}
		if (data->map.tab[y][x] == '0')
		{
			x++;
		}
		if (data->map.tab[y][x] == 'C')
		{
			x++;
		}
		if (data->map.tab[y][x] == 'E')
		{
			x++;
		}
		if (data->map.tab[y][x] == 'P')
		{
			x++;
		}
	}
	return (0);
}

int	move_player(int keysym, t_mlx *data)
{
	if (keysym == W)
	{}
	if (keysym == D)
	{}
	if (keysym == S)
	{}
	if (keysym == A)
	{

	}
	return (0);
}
