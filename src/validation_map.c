/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:56:15 by saan              #+#    #+#             */
/*   Updated: 2025/04/17 00:04:50 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_item(t_map_info *map_info)
{
	int	items[3];
	int i;
	int j;

	items[0] = 0;
	items[1] = 0;
	items[2] = 0;
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
	if (items[0] == 1 && items[1] >= 1 && items[2] == 1)
		return (1);
	else
		return (0);
}

int	is_surround_wall(t_map_info *map_info)
{
	int i;

	i = -1;
	while (++i < map_info->x_len)
	{
		if (map_info->map_blocks[0][i] != '1')
			return (0);
		if (map_info->map_blocks[map_info->y_len - 1][i] != '1')
			return (0);
	}
	i = -1;
	while (++i < map_info->y_len)
	{
		if (map_info->map_blocks[i][0] != '1')
			return (0);
		if (map_info->map_blocks[i][map_info->x_len - 1] != '1')
			return (0);
	}
	return (1);
}

int	is_rectangle(t_map_info *map_info)
{
	int	i;
	int	len;

	i = -1;
	while(map_info->map_blocks[++i])
	{
		len = ft_strlen(map_info->map_blocks[i]);
		if (map_info->x_len != len)
			return (0);
	}
	if (map_info->y_len != i)
		return (0);
	return (1);
}

int	is_valid_field(t_map_info *map_info)
{
	int	i;

	i = -1;
	while (map_info->map_blocks[++i])
		if (!is_composed_of(map_info->map_blocks[i], "01PCE"))
			return (0);
	return (1);
}

int	validation_map(t_map_info *map_info)
{
	if (!map_info->map_blocks || !map_info->map_blocks[0])
    	return (1);
	if (map_info->height > PIXEL * 10 || map_info->width > PIXEL * 18)
		return (error_msg_with_free_2_ptr("Error : invalid map (Size out of range)", map_info->map_blocks));
	if (!is_valid_field(map_info))
		return (error_msg_with_free_2_ptr("Error : invalid map (Not a valid map element)", map_info->map_blocks));
	if (!is_rectangle(map_info))
		return (error_msg_with_free_2_ptr("Error : invalid map (Map is not a rectangle)", map_info->map_blocks));
	if (!is_surround_wall(map_info))
		return (error_msg_with_free_2_ptr("Error : invalid map (Not surrounded by wall)", map_info->map_blocks));
	if (!is_valid_item(map_info))
		return (error_msg_with_free_2_ptr("Error : invalid map (Invalid number of items)", map_info->map_blocks));
	if (!is_reachable(map_info))
		return (error_msg_with_free_2_ptr("Error : invalid map (Unsolvable map)", map_info->map_blocks));
	return (0);
}
