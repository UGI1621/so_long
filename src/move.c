/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:37:50 by saan              #+#    #+#             */
/*   Updated: 2025/04/17 02:45:32 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_C_and_E(t_game *game)
{
	if (game->map_info.map_blocks[game->map_info.player_y][game->map_info.player_x] == 'C')
		game->map_info.get_c += 1;
	if (game->map_info.get_c == game->map_info.reach_c)
		game->map_info.escape = 1;
}

void	move_up(t_game *game)
{
	if (game->map_info.player_y == 1)
	{
		do_print_map(game, "up");
		return ;
	}
	if (game->map_info.map_blocks[game->map_info.player_y - 1][game->map_info.player_x] != '1')
	{
		if (!game->map_info.escape && game->map_info.map_blocks[game->map_info.player_y - 1][game->map_info.player_x] == 'E')
		{
			do_print_map(game, "up");
			return ;
		}
		game->map_info.player_y--;
		if (game->map_info.escape && game->map_info.map_blocks[game->map_info.player_y][game->map_info.player_x] == 'E')
			clear_game(game);
		check_C_and_E(game);
		game->map_info.map_blocks[game->map_info.player_y + 1][game->map_info.player_x] = '0';
		game->map_info.map_blocks[game->map_info.player_y][game->map_info.player_x] = 'P';
		game->map_info.cnt_move++;
		print_cnt_move(game->map_info.cnt_move);
	}
	do_print_map(game, "up");
}

void	move_right(t_game *game)
{
	if (game->map_info.player_x == game->map_info.x_len - 1)
	{
		do_print_map(game, "right");
		return ;
	}
	if (game->map_info.map_blocks[game->map_info.player_y][game->map_info.player_x + 1] != '1')
	{
		if (!game->map_info.escape && game->map_info.map_blocks[game->map_info.player_y][game->map_info.player_x + 1] == 'E')
		{
			do_print_map(game, "right");
			return ;
		}
		game->map_info.player_x++;
		if (game->map_info.escape && game->map_info.map_blocks[game->map_info.player_y][game->map_info.player_x] == 'E')
			clear_game(game);
		check_C_and_E(game);
		game->map_info.map_blocks[game->map_info.player_y][game->map_info.player_x - 1] = '0';
		game->map_info.map_blocks[game->map_info.player_y][game->map_info.player_x] = 'P';
		game->map_info.cnt_move++;
		print_cnt_move(game->map_info.cnt_move);
	}
	do_print_map(game, "right");
}

void	move_down(t_game *game)
{
	if (game->map_info.player_y == game->map_info.y_len - 1)
	{
		do_print_map(game, "down");
		return ;
	}
	if (game->map_info.map_blocks[game->map_info.player_y + 1][game->map_info.player_x] != '1')
	{
		if (!game->map_info.escape && game->map_info.map_blocks[game->map_info.player_y + 1][game->map_info.player_x] == 'E')
		{
			do_print_map(game, "down");
			return ;
		}
		game->map_info.player_y++;
		if (game->map_info.escape && game->map_info.map_blocks[game->map_info.player_y][game->map_info.player_x] == 'E')
			clear_game(game);
		check_C_and_E(game);
		game->map_info.map_blocks[game->map_info.player_y - 1][game->map_info.player_x] = '0';
		game->map_info.map_blocks[game->map_info.player_y][game->map_info.player_x] = 'P';
		game->map_info.cnt_move++;
		print_cnt_move(game->map_info.cnt_move);
	}
	do_print_map(game, "down");
}

void	move_left(t_game *game)
{
	if (game->map_info.player_x == 1)
	{
		do_print_map(game, "left");
		return ;
	}
	if (game->map_info.map_blocks[game->map_info.player_y][game->map_info.player_x - 1] != '1')
	{
		if (!game->map_info.escape && game->map_info.map_blocks[game->map_info.player_y][game->map_info.player_x - 1] == 'E')
		{
			do_print_map(game, "left");
			return ;
		}
		game->map_info.player_x--;
		if (game->map_info.escape && game->map_info.map_blocks[game->map_info.player_y][game->map_info.player_x] == 'E')
			clear_game(game);
		check_C_and_E(game);
		game->map_info.map_blocks[game->map_info.player_y][game->map_info.player_x + 1] = '0';
		game->map_info.map_blocks[game->map_info.player_y][game->map_info.player_x] = 'P';
		game->map_info.cnt_move++;
		print_cnt_move(game->map_info.cnt_move);
	}
	do_print_map(game, "left");
}
