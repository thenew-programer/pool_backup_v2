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
	int	ret;
	int	i;
	int	fd;

	ret = 0;
	i = 1;
	while (i < size)
	{
		fd = open_file(filenames[i]);
		if (fd == -1)
		{
			ret++;
			i++;
			continue ;
		}
		read_file(fd);
		close(fd);
		i++;
	}
	return (ret);
}
