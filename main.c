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

int	main(int ac, char **av)
{
	t_mlx	data;

	if (ac == 2)
	{
		data = check_file(av[1]);
		mlx_loop_hook(data.mlx, draw, &data);
		mlx_key_hook(data.win, key_hook, &data);
		mlx_do_sync(data.mlx);
		mlx_loop(data.mlx);
	}
	else
		printf("WRONG ARGUMENNTS NUMBERS !\n");
	return (0);
}
