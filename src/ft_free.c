/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:35:14 by snarain           #+#    #+#             */
/*   Updated: 2021/09/16 19:35:52 by snarain          ###   ########.fr       */
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
	if (data->luffy.img != NULL)
		mlx_destroy_image(data->mlx, data->luffy.img);
	if (data->luffy_move.img != NULL)
		mlx_destroy_image(data->mlx, data->luffy_move.img);
	if (data->luffy_movel.img != NULL)
		mlx_destroy_image(data->mlx, data->luffy_movel.img);
	if (data->luffy_jump.img != NULL)
		mlx_destroy_image(data->mlx, data->luffy_jump.img);
	if (data->fruit.img != NULL)
		mlx_destroy_image(data->mlx, data->fruit.img);
	if (data->door.img != NULL)
		mlx_destroy_image(data->mlx, data->door.img);
	if (data->door_open.img != NULL)
		mlx_destroy_image(data->mlx, data->door_open.img);
	if (data->ground.img != NULL)
		mlx_destroy_image(data->mlx, data->ground.img);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
}

int	ft_free(t_mlx *data)
{
	if (data->map.tab != NULL)
		free_map(data->map.tab);
	if (data->mlx != NULL)
	{
		if (data->win != NULL)
			rm_image(data);
		mlx_destroy_display(data->mlx);
	}
	free(data->mlx);
	exit(0);
	return (0);
}
