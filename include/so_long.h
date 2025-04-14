/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:13:28 by saan              #+#    #+#             */
/*   Updated: 2025/04/14 18:20:24 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

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

typedef struct	s_user {
	int		x;
	int		y;
	int		cnt_move;
}				t_user;

typedef struct	t_imgs {
	void	*land;
	void	*wall;
	void	*chara;
	void	*friend;
	void	*exit_gate;
}				t_imgs;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_user	user;
	t_imgs	imgs;
}				t_vars;

void	init_user(t_user *user);
void	init_imgs(t_imgs *imgs, t_vars *vars);
int		key_press(int keycode, t_vars *vars);
int		user_key_press(int keycode, t_user *user);

#endif
