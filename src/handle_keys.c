/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 01:06:29 by saan              #+#    #+#             */
/*   Updated: 2025/04/16 23:03:59 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit(0);
	else
		user_key_press(keycode, game);
	return (0);
}

int	user_key_press(int keycode, t_game *game)
{
	char	*temp;
	
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
