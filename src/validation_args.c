/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:37:07 by saan              #+#    #+#             */
/*   Updated: 2025/04/17 22:49:25 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_berfile(char *filename)
{
	char	*temp;

	temp = ft_strrchr(filename, '.');
	if (!temp)
		return (0);
	if (ft_strncmp(temp, ".ber", 4))
		return (0);
	if (!*(temp - 1))
		return (0);
	if (*(temp + 4))
		return (0);
	return (1);
}

int	validation_arg(int argc, char *argv[])
{
	int	fd;

	if (argc != 2)
	{
		ft_putendl_fd("Usage : ./so_long filname.ber", 1);
		return (1);
	}
	if (!is_berfile(argv[1]))
	{
		ft_putendl_fd("Error : not *.ber file", 1);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror(argv[1]);
		return (1);
	}
	close(fd);
	return (0);
}
