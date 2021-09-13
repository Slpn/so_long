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
	if (data->map.tmp != NULL)
		free(data->map.tmp);
}

void	ft_free(t_mlx *data)
{
	free(data);
	exit(0);
}

void	close_win(t_mlx *data)
{
	mlx_destroy_window(data->mlx, data->win);
	rm_image(data);
	exit(0);
}
