/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 01:02:09 by snarain           #+#    #+#             */
/*   Updated: 2021/09/04 02:15:59 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_square(t_mlx *data, char *line)
{
	if (data->map.width != ft_strlen(line))
	{
		printf("WRONG MAP\n");
		free(line);
		exit(0);
	}
	return (0);
}
