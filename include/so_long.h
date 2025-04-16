/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:13:28 by saan              #+#    #+#             */
/*   Updated: 2025/04/16 23:54:39 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# define PIXEL			100
# define MAX_WIDTH		18
# define MAX_height		10

# define X_EVENT_KEY_PRESS			1L<<0
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


typedef struct	s_map_info {
	char	**map_blocks;
	int		x_len;
	int		y_len;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		reach_c;
	int		reach_e;
	int		get_c;
	int		cnt_move;
	int		escape;
}		t_map_info;

typedef struct	t_imgs {
	void	*land;
	void	*wall;
	void	*player_up;
	void	*player_left;
	void	*player_down;
	void	*player_right;
	void	*slime;
	void	*slime_monster;
	void	*chest;
}				t_imgs;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef	struct	s_game {
	t_imgs	imgs;
	t_map_info map_info;
	t_vars	vars;
}				t_game;

void	free_2_ptr(char **ptr);

int		is_reachable(t_map_info *map_info);

int		is_composed_of(const char *str, const char *str2);
int		is_berfile(char *filename);

int		validation_arg(int argc, char *argv[]);
int		validation_map(t_map_info *map_info);

void	init_map_info(t_map_info *map_info);
void	init_imgs(t_imgs *imgs, t_vars *vars);
void	init_maps(t_map_info *map_info, char *filename);

void	do_print_map(t_game *game, char *input);
void	print_map(t_game *game);

int		key_press(int keycode, t_game *game);
int		user_key_press(int keycode, t_game *game);

void	move_up(t_game *game);
void	move_right(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);

void	clear_game(t_game *game);

int		error_msg_with_free_2_ptr(char *msg, char **ptr);

#endif
