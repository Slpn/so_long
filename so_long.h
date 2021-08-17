/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 21:53:42 by snarain           #+#    #+#             */
/*   Updated: 2021/08/17 17:51:05 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include "mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00

# define WINDOW_WIDTH	700
# define WINDOW_HEIGHT	450

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct	s_pixel
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_pixel;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int color;
}		t_rect;

#endif
