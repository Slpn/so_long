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

# define UP 1
# define DOWN 2
# define LEFT 3
# define RIGHT 4

/*
 *	WALL
 */
# define WALL "./xpm/WALL.xpm"
# define WALL_IN "./xpm/WALL_IN.xpm"
# define GRASS "./xpm/GRASS.xpm"

/*
 *	LUFFY
 */

# define LUFFY "./xpm/Luffy.xpm"
# define LUFFY_MOVE "./xpm/Luffy_move.xpm"
# define LUFFY_JUMP "./xpm/Luffy_jump.xpm"

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
	int		width;
	int		endian;
}				t_img;

typedef struct s_pos
{
	int 	move;
	int		x;
	int		y;
	int		x_t;
	int		y_t;
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
	int		moves;
	int		item;
	t_img 	ground;
	t_img 	Luffy;
	t_img 	Luffy_move;
	t_img 	Luffy_jump;
	t_img 	wall;
	t_img 	wall_in;
	t_img 	grass;
	t_img	fruit;
	t_map	map;
	t_pos	pos;
	t_pos	posP;
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
void 	init_data(t_mlx *data);
int		key_hook(int key, t_mlx *d);
void	init_sprites_and_tiles(t_mlx *d);
int	draw(t_mlx *data);

/*d->display.addr[((d->pos.x + (d->draw.x_t * BLOCK)) * d->display.bpp >> 3) + ((d->pos.y + (d->draw.y_t * BLOCK)) * d->display.length)] = tile->addr[(x_sc * tile->bpp >> 3) + (y_sc * tile->length)];
d->display.addr[((d->pos.x + (d->draw.x_t * BLOCK)) * d->display.bpp >> 3) + 1 ((d->pos.y + (d->draw.y_t * BLOCK)) * d->display.length)] = tile->addr[(x_sc * tile->bpp >> 3) + 1 + (y_sc * tile->length)];
d->display.addr[((d->pos.x + (d->draw.x_t * BLOCK)) * d->display.bpp >> 3) + 2 + ((d->pos.y + (d->draw.y_t * BLOCK)) * d->display.length)] = tile->addr[(x_sc * tile->bpp >> 3) + 2 + (y_sc * tile->length)];*/
#endif
