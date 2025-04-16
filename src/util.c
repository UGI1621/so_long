/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 01:34:25 by saan              #+#    #+#             */
/*   Updated: 2025/04/16 09:34:41 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_2_ptr(char **ptr)
{
	int i;
	
	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
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
