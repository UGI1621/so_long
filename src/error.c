/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:13:58 by saan              #+#    #+#             */
/*   Updated: 2025/04/18 00:13:25 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_msg_with_free_2_ptr(char *msg, char **ptr)
{
	ft_putendl_fd(msg, 1);
	free_2_ptr(ptr);
	return (1);
}

int	error_with_msg(char *msg)
{
	ft_putendl_fd(msg, 1);
	return (1);
}

int error_with_close(char *msg, int fd)
{
	ft_putendl_fd(msg, 1);
	close(fd);
	return (1);
}
