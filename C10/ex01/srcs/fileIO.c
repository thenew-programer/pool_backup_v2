/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileIO.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:31:28 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/16 17:43:28 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	read_file(int fd)
{
	char	c;

	while (read(fd, &c, 1) > 0)
		ft_putchar(c);
}

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 3)
	{
		ft_putstr(strerror(errno));
		// ft_cat_error(filename);
		return (-1);
	}
	return (fd);
}
