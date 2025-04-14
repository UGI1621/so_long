/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 01:08:42 by saan              #+#    #+#             */
/*   Updated: 2025/04/14 18:26:07 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_user(t_user *user)
{
	user->x = 0;
	user->y = 0;
	user->cnt_move = 0;
}

void	init_imgs(t_imgs *imgs, t_vars *vars)
{
	int	img_width;
	int	img_height;

	img_width = 100;
	img_height = 100;
	imgs->land = mlx_xpm_file_to_image(vars->mlx, "./imgs/land.xpm", &img_width, &img_height);
	imgs->exit_gate = mlx_xpm_file_to_image(vars->mlx, "./imgs/exit_gate.xpm", &img_width, &img_height);
	imgs->chara = mlx_xpm_file_to_image(vars->mlx, "./imgs/chara.xpm", &img_width, &img_height);
}
