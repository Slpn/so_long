/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 01:02:09 by snarain           #+#    #+#             */
/*   Updated: 2021/09/10 01:07:17 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	rm_image(t_mlx *data)
{
	if (data->wall.img != NULL)
		mlx_destroy_image(data->mlx, data->wall.img);
	if (data->wall_in.img != NULL)
		mlx_destroy_image(data->mlx, data->wall_in.img);
	if (data->grass.img != NULL)
		mlx_destroy_image(data->mlx, data->grass.img);
	if (data->Luffy.img != NULL)
		mlx_destroy_image(data->mlx, data->Luffy.img);
	if (data->Luffy_move.img != NULL)
		mlx_destroy_image(data->mlx, data->Luffy_move.img);
	if (data->Luffy_jump.img != NULL)
		mlx_destroy_image(data->mlx, data->Luffy_jump.img);
	if (data->fruit.img != NULL)
		mlx_destroy_image(data->mlx, data->fruit.img);
}

void	ft_free(t_mlx *data)
{
	free_map(data->map.tab);
	if (data->mlx != NULL)
	{
		if (data->win != NULL)
				rm_image(data);
		mlx_destroy_window(data->mlx, data->win);
	}
	free(data->mlx);
	exit(0);
}
