/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:19:06 by snarain           #+#    #+#             */
/*   Updated: 2021/09/01 20:34:52 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	*render(t_mlx *data)
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

int	key_hook(int keysym, t_mlx *data)
{
	int	y = 10;
	int	x = 10;
	if (keysym == 119)
	{
		printf("%d\n", data->i);
		mlx_string_put(data->mlx, data->win, y, x, RED_PIXEL, "LUFFY");
	}
	data->i += 1;
	return (0);
}

int main(void)
{
	t_mlx	data;
	int hei;
	int wid;
	char *path_xpm = "./xpm/Luffy-removebg-preview.xpm";
	data.mlx = mlx_init();
	data.i = 0;
	if (data.mlx == NULL)
		return (MLX_ERROR);
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, 
			"so_long");
	if (data.win == NULL)
	{
		free(data.mlx);
		return (MLX_ERROR);
	}
/*	data.img = mlx_xpm_file_to_image(data.mlx, path_xpm, &hei, &wid);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 10, 50);
	//mlx_loop_hook(data.mlx, render, &data);*/
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
	//free(data.mlx);
	return (0);
}
