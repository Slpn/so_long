/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:12:44 by snarain           #+#    #+#             */
/*   Updated: 2021/09/09 19:39:17 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	init_mlx(t_mlx *data)
{
	data->win_width = (data->map.width * BLOCK);
	data->win_length = (data->map.length * BLOCK);
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_free(data);
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_length,
			"so_long");
	if (!data->win)
		ft_free(data);
	return (0);
}
