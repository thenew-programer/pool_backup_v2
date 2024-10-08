/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:40:47 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/16 17:51:27 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

int	ft_cat(int size, char **filenames)
{
	int		ret;
	int		i;
	int		fd;
	int		bytes_read;
	char	buffer[BUFFER_SIZE];

	ret = 0;
	i = 0;
	while (++i < size)
	{
		fd = open_file(filenames[i]);
		if (fd == -1)
		{
			ret++;
			continue ;
		}
		while (1)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read > 0)
				write(1, buffer, bytes_read);
			else
				break ;
		}
		close(fd);
	}
	return (ret);
}
