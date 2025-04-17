/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:24:41 by saan              #+#    #+#             */
/*   Updated: 2025/04/18 00:25:54 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_items(t_map_info *map_info, int *items)
{
	int i;
	int j;

	i = -1;
	while (map_info->map_blocks[++i])
	{
		j = -1;
		while(map_info->map_blocks[i][++j])
		{
			if (map_info->map_blocks[i][j] == 'P')
				items[0]++;
			if (map_info->map_blocks[i][j] == 'C')
				items[1]++;
			if (map_info->map_blocks[i][j] == 'E')
				items[2]++;
		}
	}
}