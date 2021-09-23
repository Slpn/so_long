/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:27:54 by snarain           #+#    #+#             */
/*   Updated: 2021/09/16 19:36:59 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_name(char *av)
{
	int	i;

	i = 0;
	i = (ft_strleng(av) - 4);
	if (ft_strncmp((av + i), ".ber", 4) != 0)
	{
		printf("Error : WRONG FILE FORMAT !\n");
		exit(EXIT_FAILURE);
	}
}

int	check_open(t_mlx *data, char *av)
{
	char	*line;
	int		tmp;

	tmp = open(av, O_DIRECTORY);
	if (tmp != -1)
	{
		printf("Error \n: IT'S A DIRECTORY \n");
		exit(0);
	}
	check_name(av);
	data->map.fd = open(av, O_RDONLY);
	if (data->map.fd == -1)
	{
		printf("Error \n CAN'T OPEN THIS FILE !\n");
		exit(0);
	}
	get_next_line(data->map.fd, &line);
	data->map.width = ft_strleng(line);
	line = ft_strjoing(line, "\n");
	data->map.tmp = ft_strdupg(line);
	free(line);
	return (0);
}

t_mlx	check_file(char *av)
{
	t_mlx	data;
	char	*line;

	init_data(&data);
	check_open(&data, av);
	while (get_next_line(data.map.fd, &line) == 1)
	{
		check_square(&data, line);
		line = ft_strjoing(line, "\n");
		data.map.tmp = ft_strjoing(data.map.tmp, line);
		data.map.length += 1;
		free(line);
	}
	data.map.tab = ft_split(data.map.tmp, '\n');
	parse_map(&data);
	close (data.map.fd);
	free(data.map.tmp);
	init_mlx(&data);
	if (line != NULL)
		free(line);
	return (data);
}
