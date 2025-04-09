/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:11:23 by saan              #+#    #+#             */
/*   Updated: 2025/04/09 21:15:40 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		add_shade(int color, double distance)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = (int)(get_t(color) * (1.0 - distance));
	r = (int)(get_r(color) * (1.0 - distance));
	g = (int)(get_g(color) * (1.0 - distance));
	b = (int)(get_b(color) * (1.0 - distance));
	return (create_trgv(t,r,g,b));
}

int		get_opposite(int color)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = get_t(color);
	r = 255 - get_r(color);
	g = 255 - get_g(color);
	b = 255 - get_b(color);
	return (create_trgv(t, r, g, b));
}
