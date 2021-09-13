/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:19:06 by snarain           #+#    #+#             */
/*   Updated: 2021/09/08 21:37:09 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keysym, t_mlx *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	data;

	if (ac == 2)
	{
		check_file(av[1], &data);
		init_mlx(&data);
		mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
		mlx_key_hook(data.win, key_hook, &data);
		mlx_loop_hook(data.mlx, draw, &data);
		mlx_loop(data.mlx);
	}
	else
		printf("WRONG ARGUMENNTS NUMBERS !\n");
	return (0);
}
