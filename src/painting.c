/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:14:02 by saan              #+#    #+#             */
/*   Updated: 2025/04/17 00:19:49 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_game(t_game *game)
{
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	ft_putendl_fd("clear!!", 1);
	free_2_ptr(game->map_info.map_blocks);
	exit(0);
}

void	paint_player(t_game *game, char *input, int i, int j)
{
	if (!ft_strncmp(input, "down", 4))
	{
		mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->imgs.player_down, j * PIXEL, i * PIXEL);
	}
	else if (!ft_strncmp(input, "right", 4))
	{
		mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->imgs.player_right, j * PIXEL, i * PIXEL);
	}
	else if (!ft_strncmp(input, "left", 4))
	{
		mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->imgs.player_left, j * PIXEL, i * PIXEL);
	}
	else if (!ft_strncmp(input, "up", 4))
	{
		mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->imgs.player_up, j * PIXEL, i * PIXEL);
	}
}	

void	do_print_map(t_game *game, char *input)
{
	int	i;
	int	j;

	i = -1;
	while(game->map_info.map_blocks[++i])
	{
		j = -1;
		while (game->map_info.map_blocks[i][++j])
		{
			if (game->map_info.map_blocks[i][j] == '1')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->imgs.wall, j * PIXEL, i * PIXEL);
			if (game->map_info.map_blocks[i][j] == '0')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->imgs.land, j * PIXEL, i * PIXEL);
			if (game->map_info.map_blocks[i][j] == 'C')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->imgs.slime, j * PIXEL, i * PIXEL);
			if (game->map_info.map_blocks[i][j] == 'P')
				paint_player(game, input, i, j);
			if (game->map_info.map_blocks[i][j] == 'E')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->imgs.chest, j * PIXEL, i * PIXEL);
			}
	}
}

void	print_map(t_game *game)
{
	do_print_map(game, "down");
}
