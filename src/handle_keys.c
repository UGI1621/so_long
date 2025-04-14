/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 01:06:29 by saan              #+#    #+#             */
/*   Updated: 2025/04/13 06:45:25 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	add_and_print_cnt_move(t_user *user)
{
	char	*temp;

	user->cnt_move++;
	temp = ft_itoa(user->cnt_move);
	ft_putendl_fd(temp, 1);
	free(temp);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		exit(0);
	else
		user_key_press(keycode, &vars->user);
	return (0);
}
int	user_key_press(int keycode, t_user *user)
{
	char	*temp;
	
	if (keycode == KEY_W)
		add_and_print_cnt_move(user);
	else if (keycode == KEY_A)
		add_and_print_cnt_move(user);
	else if (keycode == KEY_S)
		add_and_print_cnt_move(user);
	else if (keycode == KEY_D)
		add_and_print_cnt_move(user);
	return (0);
}
