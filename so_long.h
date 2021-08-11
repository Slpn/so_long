/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 21:53:42 by snarain           #+#    #+#             */
/*   Updated: 2021/08/11 03:19:35 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include "minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

#endif
