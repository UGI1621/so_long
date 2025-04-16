/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 01:06:29 by saan              #+#    #+#             */
/*   Updated: 2025/04/17 02:45:41 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	destroy_all(game);
	free_2_ptr(game->map_info.map_blocks);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		destroy_all(game);
		free_2_ptr(game->map_info.map_blocks);
		exit(0);
	}
	else
		user_key_press(keycode, game);
	return (0);
}

int	user_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_up(game);
	else if (keycode == KEY_D)
	{
		move_right(game);
	}
	else if (keycode == KEY_S)
	{
		move_down(game);
	}
	else if (keycode == KEY_A)
	{
		move_left(game);
	}
	return (0);
}
