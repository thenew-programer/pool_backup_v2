/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:40:47 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/16 19:10:41 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

long long	get_size(char *filename)
{
	int			fd;
	long long	size;
	char		c;

	size = 0;
	fd = open_file(filename);
	if (fd == -1)
		return (-1);
	while (read(fd, &c, 1) > 0)
		size++;
	close(fd);
	return size;
}

int	ft_tail(int argc, char **filenames, long long bytes)
{
	int			fd;
	long long	size;
	int			i;

	if (bytes == 0)
		return (0);
	i = 0;
	while (++i < argc)
	{
		if ((filenames[i][0] != '-' && filenames[i][1] != 'c' && filenames[i][2] != 0))
		{
			size = get_size(filenames[i]);
			if (size == -1)
				continue ;
			if (argc > 4)
				ft_tail_header(filenames[i]);
			fd = open_file(filenames[i]);
			if (fd == -1)
				continue ;
			read_file(fd, size, bytes, M_FILE);
			close(fd);
			if (i != argc - 3)
				ft_putchar('\n');
		}
	}
	return (0);
}
