/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:19:06 by snarain           #+#    #+#             */
/*   Updated: 2021/08/12 18:55:44 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define MLX_ERROR 1

int	colors(t_mlx *data)
{
	if (data->win != NULL)
		mlx_pixel_put(data->mlx, data->win, 
				WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, RED_PIXEL);
	return (0);
}

int	handle_keypress(int keysym, t_mlx *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	return (0);
}

int main(void)
{
	t_mlx	data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (MLX_ERROR);
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, 
			"My first window!");
	if (data.win == NULL)
	{
		free(data.win);
		return (MLX_ERROR);
	}
	mlx_loop_hook(data.mlx, &colors, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx);
	free(data.mlx);
	return (0);
}
