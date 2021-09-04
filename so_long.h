/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 21:53:42 by snarain           #+#    #+#             */
/*   Updated: 2021/09/04 19:54:45 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "./src/libft/libft.h"
# include "./src/GNL/get_next_line.h"

# define MLX_ERROR		1
# define RED_PIXEL		0xFF0000
# define GREEN_PIXEL	0xFF00

# define WINDOW_WIDTH	700
# define WINDOW_HEIGHT	450
/*
 * TOUCH
 */
# define W 119
# define D 100
# define S 115
# define A 97
# define ESC 65307
/*
 *	LUFFY
 */

# define LUFFY_STRAIGHT	"./xpm/Luffy.xpm"

/*
 *	COLLECTIBLES
 */
# define DEMON_FRUIT "./xpm/demon_fruit.xpm"

typedef struct	m_map
{
	char	**tab;
	char	*tmp;
	int		fd;
	int		width;
	int		length;
}	t_map;

typedef struct	s_pixel
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_pixel;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		index;
	int		i;
	t_pixel img_mlx;
	t_map	map;
}	t_mlx;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int color;
}		t_rect;

int		get_next_line(int fd, char **line);
int		parse_map(char *line);
int		check_file(char *av);
int		check_name(char *av);
int		check_square(t_mlx *data, char *line);

#endif
