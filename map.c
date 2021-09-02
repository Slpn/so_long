/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 18:55:54 by snarain           #+#    #+#             */
/*   Updated: 2021/09/02 19:44:45 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check(char **line)
{
	int i;

	i = 0;

	while (*line[i])
	{
		if (*line[i] == '0' || *line[i] == '1' || *line[i] == 'C' || 
				*line[i] == 'E' || *line[i] == 'P')
			i++;
		else
			return (-1);
	}
	return (0);
}

int	parse_map(char **line)
{
	int	i;
	
	i = 0;
	while (line[i])
	{
		if (ft_check(line) == -1)
		{
			printf("MAP ERROR !\n");
			exit(EXIT_FAILURE);
		}
		else
			printf("GOOD MAP!\n");
		i++;
	}
	return (0);
}
