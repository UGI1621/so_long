/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 01:34:25 by saan              #+#    #+#             */
/*   Updated: 2025/04/18 00:10:28 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_all(t_game *game)
{
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	mlx_destroy_image(game->vars.mlx, game->imgs.land);
	mlx_destroy_image(game->vars.mlx, game->imgs.wall);
	mlx_destroy_image(game->vars.mlx, game->imgs.player_down);
	mlx_destroy_image(game->vars.mlx, game->imgs.player_left);
	mlx_destroy_image(game->vars.mlx, game->imgs.player_right);
	mlx_destroy_image(game->vars.mlx, game->imgs.player_up);
	mlx_destroy_image(game->vars.mlx, game->imgs.slime);
	mlx_destroy_image(game->vars.mlx, game->imgs.slime_monster);
	mlx_destroy_image(game->vars.mlx, game->imgs.chest);
	mlx_destroy_display(game->vars.mlx);
	free(game->vars.mlx);
}

void	print_cnt_move(int cnt)
{
	char	*temp;

	temp = ft_itoa(cnt);
	ft_putendl_fd(temp, 1);
	free(temp);
}

void	free_2_ptr(char **ptr)
{
	int i;
	
	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
}

int	gnl_line_count(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filename, O_RDONLY);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	is_composed_of(const char *str, const char *str2)
{
	int	chars[256];
	int	i;

	i = -1;
	while(++i < 256)
		chars[i] = 0;
	i = -1;
	while (str2[++i])
		chars[(unsigned char)str2[i]] += 1;
	i = -1;
	while (str[++i])
		if (chars[(unsigned char)str[i]] == 0)
			return (0);
	return (1);
}
