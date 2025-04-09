/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:25:55 by saan              #+#    #+#             */
/*   Updated: 2025/04/09 21:17:30 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <unistd.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	make_name_of_my_soulmate(t_data *img)
{
	int	i;

	int	color = create_trgv(0,255,255,255);
	// t
	i = -1;
	while (++i < 50)
		my_mlx_pixel_put(img, i, 0, color);
	i = -1;
	while (++i < 50)
		my_mlx_pixel_put(img, i, 25, color);
	i = -1;
	while (++i < 50)
		my_mlx_pixel_put(img, i, 50, color);
	i = -1;
	while (++i < 50)
		my_mlx_pixel_put(img, 0, i, color);

	// ae
	i = -1;
	while (++i < 50)
	{
		my_mlx_pixel_put(img, 70, i, color);
		if(i == 25)
		{
			int j = -1;
			while (++j < 10)
			{
				my_mlx_pixel_put(img, j + 70, 25, color);
			}
		}
		my_mlx_pixel_put(img, 80, i, color);
	}
}

void	make_gradation(t_data *img, int color)
{
	int	i = -1;
	while(++i < 300)
	{
		color = add_shade(color, 0.003);
		int	j = -1;
		while(++j < 100)
		my_mlx_pixel_put(img, i, j, color);
	}
}

void	make_opposite(t_data *img, int color)
{
	int	i = -1;
	while(++i < 300)
	{
		int	j = -1;
		while(++j < 100)
		my_mlx_pixel_put(img, i, j, color);
	}
	color = get_opposite(color);
	while(++i < 600)
	{
		int j = -1;
		while(++j < 100)
		my_mlx_pixel_put(img, i, j, color);
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		width = 800;
	int		height = 600;
	int		color = create_trgv(0, 0, 200, 255);
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, height, "hello so_long");
	img.img = mlx_new_image(mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// make_name_of_my_soulmate(&img);
	// make_gradation(&img, color);
	make_opposite(&img, color);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
