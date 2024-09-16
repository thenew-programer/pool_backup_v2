/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileIO.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:31:28 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/16 19:08:55 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	read_file(int fd, long long size, long long bytes, int mode)
{
	char		c;
	long long	i;
	i = -1;
	if (mode == M_STDIN)
	{
		while (read(fd, &c, 1) > 0)
		{
			++i;
		}
	}
	else if (mode == M_FILE)
	{
		while (read(fd, &c, 1) > 0)
		{
			if (++i > (size - bytes - 1))
				ft_putchar(c);
		}
	}
}

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 3)
	{
		ft_tail_error(filename);
		return (-1);
	}
	return (fd);
}
