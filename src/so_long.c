/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 00:59:55 by saan              #+#    #+#             */
/*   Updated: 2025/04/17 02:46:39 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	init_map_info(&game.map_info);
	if (validation_arg(argc, argv))
		return (0);
	init_maps(&game.map_info, argv[1]);
	if (validation_map(&game.map_info))
		return (0);
	game.vars.mlx = mlx_init();
	game.vars.win = mlx_new_window(game.vars.mlx, game.map_info.width, game.map_info.height, "so_long");
	init_imgs(&game.imgs, &game.vars);
	print_map(&game);
	mlx_hook(game.vars.win, 17, 0, close_window, &game);
	mlx_hook(game.vars.win, 2, X_EVENT_KEY_PRESS, key_press, &game);
	mlx_loop(game.vars.mlx);
	return (0);
}
