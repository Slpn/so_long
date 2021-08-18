/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:19:06 by snarain           #+#    #+#             */
/*   Updated: 2021/08/18 19:04:34 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define MLX_ERROR 1

int	render_rect(t_mlx *data, t_rect rect)
{
	int	i;
	int j;

	if (data->win == NULL)
		return (-1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x +rect.height)
			mlx_pixel_put(data->mlx, data->win, j++, i, rect.color);
		++i;
	}
	return (0);
}

int	render(t_mlx *data)
{
	render_rect(data, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 
			100, 100, RED_PIXEL});
	render_rect(data, (t_rect){0, 10
			, 100, 100, GREEN_PIXEL});
	return (0);
}

int	colors(t_mlx *data)
{
	if (data->win != NULL)
		mlx_pixel_put(data->mlx, data->win, 
				WINDOW_WIDTH / 10, WINDOW_HEIGHT / 10, RED_PIXEL);
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
	int render;
	int data;
	int hei;
	int wid;
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (MLX_ERROR);
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, 
			"My first window!");
	if (data.win == NULL)
	{
		free(data.mlx);
		return (MLX_ERROR);
	}
	data.img = mlx_xpm_file_to_image(data.mlx, "/xpm/Luffy-removebg-preview.xpm", &hei, &wid);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 10, 10);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx);
	free(data.mlx);
	return (0);
}
