/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 21:53:42 by snarain           #+#    #+#             */
/*   Updated: 2021/09/10 02:56:51 by snarain          ###   ########.fr       */
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

/*
 * TOUCH
 */
# define W 119
# define D 100
# define S 115
# define A 97
# define ESC 65307
# define BLOCK	48

/*
 *	WALL
 */
# define WALL "./xpm/WALL.xpm"
# define WALL_IN "./xpm/WALL_IN.xpm"
# define GRASS "./xpm/GRASS.xpm"

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
	int		player;
	int		collect;
	int		exit;
	int		width;
	int		length;
}	t_map;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
}				t_img;

typedef struct s_pos
{
	int	x;
	int	y;
	int	width;
	int	height;
}		t_pos;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		win_width;
	int		win_length;
	int		width;
	int		length;
	t_img img_Luffy;
	t_img img_wall;
	t_img img_wall_in;
	t_img img_grass;
	t_map	map;
	t_pos	pos;
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
int		parse_map(t_mlx *data);
int		check_file(char *av, t_mlx *data);
int		check_name(char *av);
int		check_square(t_mlx *data, char *line);
int		init_mlx(t_mlx *data);
void	ft_free(t_mlx *data);

#endif
