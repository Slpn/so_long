/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 21:53:42 by snarain           #+#    #+#             */
/*   Updated: 2021/08/18 18:53:49 by snarain          ###   ########.fr       */
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

# define W 119
# define D 100
# define S 115
# define A 97
# define ESC 65307

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_mlx;

typedef struct	s_pixel
{
	void	*img;
	char	*addr;
	int		bpp;
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
