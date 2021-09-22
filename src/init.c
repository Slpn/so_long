/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:21:46 by snarain           #+#    #+#             */
/*   Updated: 2021/09/16 19:22:39 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_mlx *data)
{
	data->wall.img = NULL;
	data->wall_in.img = NULL;
	data->grass.img = NULL;
	data->Luffy.img = NULL;
	data->fruit.img = NULL;
	data->map.length = 1;
	data->map.width = 0;
	data->moves = 0;
	data->item = 0;
	data->ground.img = NULL;
	data->mlx = NULL;
	data->win = NULL;
	data->posP.move = STRAIGHT;
	data->map.player = 0;
	data->item = 0;
	data->map.exit = 0;
	data->map.tmp = NULL;
}
