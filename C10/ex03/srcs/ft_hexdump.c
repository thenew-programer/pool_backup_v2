/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 04:13:36 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/17 04:15:42 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int		get_file_size(char *filename)
{
	char	buffer;
	int		size;
	int		fd;

	buffer = 0;
	size = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "ft_hexdump: ", 12);
		while (*filename)
			write(2, filename++, 1);
		write(2, ": No such file or directory\n", 28);
	}
	else
		while (read(fd, &buffer, 1) > 0)
			++size;
	close(fd);
	return size;
}

void	ft_hexdump(char *str, int size)
{
	int		i;
	int		j;

	j = 0;
	while (str[j])
	{
		ft_print_offset(j, 1);
		write(1, "  ", 2);
		i = j - 1;
		while (++i < 16 + j)
			ft_print_hex(*(str + i), i, size);
		i = j - 1;
		write(1, "|", 1);
		while (++i < 16 + j && str[i])
			ft_print_ascii(*(str + i));
		write(1, "|\n", 2);
		j += 16;
	}
	ft_print_offset(j, 1);
	write(1, "\n", 1);
	free(str);
}
