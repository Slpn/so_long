/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:27:54 by snarain           #+#    #+#             */
/*   Updated: 2021/09/03 19:19:00 by snarain          ###   ########.fr       */
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

int	check_map(t_mlx	*data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	return (0);
}

int	check_file(char *av)
{
	t_mlx	data;
	int		fd;
	int		i;
	char	*line;
	char	**tab;

	i = 0;
	data.index = 0;
	fd = open(av, O_RDONLY);
	if (!fd)
	{
		printf("CAN'T OPEN THIS FILE !\n");
		return (0);
	}
	check_name(av);
	while (get_next_line(fd, &line) == 1)
	{
		data.index += 1;
	}
/*	tab = malloc(sizeof(char *) * (data.index + 1));
	if (!tab)
		return (0);
	while (line[i] != '\n')
		i++;
	*tab = malloc(sizeof(char) * (i + 1));
	if (*tab)
		return (0);*/
	return (0);
}
