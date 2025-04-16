/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_reachable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:07:11 by saan              #+#    #+#             */
/*   Updated: 2025/04/16 23:48:52 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player_position(t_map_info *map_info)
{
	int	i;
	int	j;

	i = -1;
	while (map_info->map_blocks[++i])
	{
		j = -1;
		while (map_info->map_blocks[i][++j])
		{
			if (map_info->map_blocks[i][j] == 'P')
			{
				map_info->player_x = j;
				map_info->player_y = i;
				return ;
			}
		}
	}
}

void	dfs(t_map_info *map_info, int **copied_map, int x, int y)
{
	if (x < 0 || y < 0 || x > map_info->x_len || y > map_info->y_len)
		return ;
	if ((map_info->map_blocks[y][x] == '1') || copied_map[y][x])
		return ;
	copied_map[y][x] = 1;
	if (map_info->map_blocks[y][x] == 'C')
		map_info->reach_c++;
	else if (map_info->map_blocks[y][x] == 'E')
		map_info->reach_e++;
	dfs(map_info, copied_map, x + 1, y);
	dfs(map_info, copied_map, x - 1, y);
	dfs(map_info, copied_map, x, y + 1);
	dfs(map_info, copied_map, x, y - 1);
}

int	is_reachable(t_map_info *map_info)
{
	int	**copied_map;
	int	i;

	i = -1;
	set_player_position(map_info);
	copied_map = (int **)ft_calloc(map_info->y_len + 1, sizeof(int *));
	while(++i < map_info->y_len)
		copied_map[i] = (int *)ft_calloc(map_info->x_len, sizeof(int));
	i = -1;
	dfs(map_info, copied_map, map_info->player_x, map_info->player_y);
	while (copied_map[++i])
		free(copied_map[i]);
	free(copied_map);
	if (map_info->reach_c && map_info->reach_e)
		return (1);
	return (0);
}
