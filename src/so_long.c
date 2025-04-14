/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 00:59:55 by saan              #+#    #+#             */
/*   Updated: 2025/04/14 18:30:24 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(void)
{
	t_vars	vars;
	t_imgs	imgs;

	init_user(&vars.user);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "so_long");
	init_imgs(&imgs, &vars);
	mlx_hook(vars.win, 2, X_EVENT_KEY_PRESS, key_press, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, imgs.land, 0, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, imgs.chara, 64, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, imgs.exit_gate, 128, 0);
	mlx_loop(vars.mlx);
	return (0);
}
