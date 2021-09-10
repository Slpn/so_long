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
	if (data->img_wall.img != NULL)
		mlx_destroy_image(data->mlx, data->img_wall.img);
	if (data->img_wall_in.img != NULL)
		mlx_destroy_image(data->mlx, data->img_wall.img);
	if (data->img_wall.img != NULL)
			mlx_destroy_image(data->mlx, data->img_wall.img);
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
