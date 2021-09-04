/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:27:54 by snarain           #+#    #+#             */
/*   Updated: 2021/09/04 20:07:14 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_name(char *av)
{
	int	i;

	i = 0;
	while (av[i] && av[i] != '.')
		i++;
	if (ft_strncmp((av + i), ".ber", 4) != 0)
	{
		printf("WRONG FILE FORMAT !\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	check_open(t_mlx *data, char *av)
{
	char	*line;
	
	data->map.fd = 0;
	data->map.fd = open(av, O_RDONLY);
	if (!data->map.fd)
	{
		printf("CAN'T OPEN THIS FILE !\n");
		exit(0);
	}
	check_name(av);
	get_next_line(data->map.fd, &line);
	data->map.width = ft_strlenG(line);
	line = ft_strjoinG(line, "\n");
	data->map.tmp = ft_strdupG(line);
	free(line);
	return (0);
}

int	check_file(char *av)
{
	t_mlx	data;
	char	*line;

	data.map.length = 0;
	data.map.width = 0;
	data.map.tmp = ft_strdupG("");
	check_open(&data, av);
	while (get_next_line(data.map.fd, &line) == 1)
	{
		check_square(&data, line);
		line = ft_strjoinG(line, "\n");
		data.map.tmp = ft_strjoinG(data.map.tmp, line);
		free(line);
	}
	parse_map(data.map.tmp);
	data.map.tab = ft_split(data.map.tmp, '\0');
	free(data.map.tmp);
	free(line);
	return (0);
}
