/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 01:08:42 by saan              #+#    #+#             */
/*   Updated: 2025/04/17 02:38:07 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_imgs(t_imgs *imgs, t_vars *vars)
{
	int	img_width;
	int	img_height;

	imgs->land = mlx_xpm_file_to_image(vars->mlx, "./imgs/land.xpm", &img_width,
			&img_height);
	imgs->wall = mlx_xpm_file_to_image(vars->mlx, "./imgs/wall.xpm", &img_width,
			&img_height);
	imgs->player_down = mlx_xpm_file_to_image(vars->mlx,
			"./imgs/player_down.xpm", &img_width, &img_height);
	imgs->player_up = mlx_xpm_file_to_image(vars->mlx, "./imgs/player_up.xpm",
			&img_width, &img_height);
	imgs->player_left = mlx_xpm_file_to_image(vars->mlx,
			"./imgs/player_left.xpm", &img_width, &img_height);
	imgs->player_right = mlx_xpm_file_to_image(vars->mlx,
			"./imgs/player_right.xpm", &img_width, &img_height);
	imgs->slime = mlx_xpm_file_to_image(vars->mlx, "./imgs/slime.xpm",
			&img_width, &img_height);
	imgs->slime_monster = mlx_xpm_file_to_image(vars->mlx,
			"./imgs/slime_monster.xpm", &img_width, &img_height);
	imgs->chest = mlx_xpm_file_to_image(vars->mlx, "./imgs/chest.xpm",
			&img_width, &img_height);
}

void	init_map_info(t_map_info *map_info)
{
	map_info->width = 0;
	map_info->height = 0;
	map_info->x_len = 0;
	map_info->y_len = 0;
	map_info->player_x = -1;
	map_info->player_y = -1;
	map_info->reach_c = 0;
	map_info->reach_e = 0;
	map_info->get_c = 0;
	map_info->cnt_move = 0;
	map_info->escape = 0;
}

void	remove_newline(t_map_info *map_info)
{
	int	len;
	int	i;

	i = -1;
	while (map_info->map_blocks[++i])
	{
		len = ft_strlen(map_info->map_blocks[i]);
		if (map_info->map_blocks[i][len - 1] == '\n')
		{
			map_info->map_blocks[i][len - 1] = '\0';
			len--;
		}
	}
	map_info->x_len = ft_strlen(map_info->map_blocks[0]);
	map_info->y_len = i;
	map_info->height = i * PIXEL;
	map_info->width = map_info->x_len * PIXEL;
}

void	init_maps(t_map_info *map_info, char *filename)
{
	char	*line;
	char	checker;
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	map_info->map_blocks = (char **)ft_calloc(11, sizeof(char *));
	i = -1;
	line = get_next_line(fd);
	while (line)
	{
		map_info->map_blocks[++i] = line;
		line = get_next_line(fd);
	}
	close(fd);
	if (read(fd, &checker, 1) > 0)
		error_msg_with_free_2_ptr("Error : GNL", map_info->map_blocks);
	remove_newline(map_info);
}
