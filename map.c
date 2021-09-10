/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 18:55:54 by snarain           #+#    #+#             */
/*   Updated: 2021/09/06 21:19:08 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_square(t_mlx *data, char *line)
{
	if (data->map.width != ft_strlenG(line))
	{
		printf("ERROR : WRONG MAP\n");
		free(line);
		exit(0);
	}
	return (0);
}

int	check_rect(t_mlx *data)
{
	int	x;
	int	y;
	int	len_x;
	int	len_y;

	y = -1;
	len_x = data->map.width - 1;
	len_y = data->map.length - 1;
	while (data->map.tab[++y])
		if (data->map.tab[y][0] != '1')
			return (0);
	y = -1;
	while (data->map.tab[++y])
		if (data->map.tab[y][len_x] != '1')
			return (0);
	x = -1;
	while (data->map.tab[0][++x] && x <= len_x)
		if (data->map.tab[0][x] != '1')
			return (0);
	x = -1;
	while (data->map.tab[len_y][++x] && x <= len_x)
		if (data->map.tab[len_y][x] != '1')
			return (0);
	return (1);
}

int	in_map(t_mlx *data)
{
	data->map.player = 0;
	data->map.collect = 0;
	data->map.exit = 0;
	while (*data->map.tmp)
	{
		if(*data->map.tmp == 'P')
			data->map.player += 1;
		if(*data->map.tmp == 'C')
			data->map.collect += 1;
		if(*data->map.tmp == 'E')
			data->map.exit += 1;
		data->map.tmp++;
	}
	return (0);
}

int	ft_check(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'C' ||
				line[i] == 'E' || line[i] == 'P' ||
				line[i] == '\n' || line[i] =='\0')
			i++;
		else
			return (-1);
	}
	return (0);
}

int	parse_map(t_mlx *data)
{
	in_map(data);
	if (ft_check(data->map.tmp) == -1 || check_rect(data) == 0 ||
			data->map.player != 1 || data->map.collect == 0 ||
			data->map.exit == 0)
	{
		printf("ERROR : MAP ERROR !\n");
		exit(EXIT_FAILURE);
	}
	else
		printf("GOOD MAP!\n");
	return (0);
}
