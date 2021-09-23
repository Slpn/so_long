/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 21:53:42 by snarain           #+#    #+#             */
/*   Updated: 2021/09/17 19:31:26 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "./libft/libft.h"
# include "./GNL/get_next_line.h"

/*
 * TOUCH
 */

# define W 119
# define D 100
# define S 115
# define A 97
# define ESC 65307
# define BLOCK 48

/*
 *	WALL
 */
# define WALL "./xpm/WALL_IN.xpm"
# define WALL_IN "./xpm/wather.xpm"
# define GRASS "./xpm/GRASS.xpm"
# define DOOR "./xpm/door.xpm"
# define DOOR_OPEN "./xpm/door_open.xpm"

/*
 *	LUFFY
 */

# define LUFFY "./xpm/Luffy.xpm"
# define LUFFY_MOVE "./xpm/Luffy_move.xpm"
# define LUFFY_MOVEL "./xpm/Luffy_moveL.xpm"
# define LUFFY_JUMP "./xpm/Luffy_jump.xpm"

/*
 *	COLLECTIBLES
 */
# define DEMON_FRUIT "./xpm/demon_fruit.xpm"

typedef enum s_dir
{
	STRAIGHT,
	UP,
	DOWN,
	RIGHT,
	LEFT
}	t_dir;

typedef struct m_map
{
	char	**tab;
	char	*tmp;
	int		fd;
	int		player;
	int		exit;
	int		width;
	int		length;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		line;
	int		width;
	int		endian;
}				t_img;

typedef struct s_pos
{
	int		move;
	int		x;
	int		y;
	int		x_s;
	int		y_s;
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
	t_img	ground;
	t_img	luffy;
	t_img	luffy_move;
	t_img	luffy_movel;
	t_img	luffy_jump;
	t_img	wall;
	t_img	wall_in;
	t_img	grass;
	t_img	fruit;
	t_img	door;
	t_img	door_open;
	t_map	map;
	t_pos	pos;
	t_pos	posp;
}	t_mlx;

int		get_next_line(int fd, char **line);
int		parse_map(t_mlx *data);
t_mlx	check_file(char *av);
void	check_name(char *av);
int		check_square(t_mlx *data, char *line);
void	init_mlx(t_mlx *data);
int		ft_free(t_mlx *data);
void	init_data(t_mlx *data);
int		key_hook(int key, t_mlx *d);
void	init_sprites_and_tiles(t_mlx *d);
int		draw(t_mlx *data);
void	free_map(char **map);
void	draw_tile(t_mlx *d, t_img *tile);
void	draw_sprite(t_mlx *d, t_img *tile);
void	draw_player(t_mlx *data);
void	draw_player_sprite(t_mlx *d, t_img *tile);

#endif
