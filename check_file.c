/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:27:54 by snarain           #+#    #+#             */
/*   Updated: 2021/09/04 02:16:50 by snarain          ###   ########.fr       */
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
	char	*tmp;

	i = 0;
	data.map.length = 0;
	fd = open(av, O_RDONLY);
	if (!fd)
	{
		printf("CAN'T OPEN THIS FILE !\n");
		return (0);
	}
	check_name(av);
	get_next_line(fd, &line);
	data.map.width = ft_strlen(line);
	free(line);
	data.map.tab = malloc(sizeof(char *) * (data.map.width + 1));
	if (!data.map.tab)
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		check_square(&data, line);
		line = ft_strjoin(line, "\n");
		data.map.tab[data.map.length] = ft_strdup(line);
		data.map.length += 1;
		free(line);
	}
	data.map.tab[data.map.length] = ft_strdup(line);
	data.map.tab[data.map.length + 1] = NULL;
	free(line);
	return (0);
}
