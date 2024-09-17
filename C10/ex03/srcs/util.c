/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 04:15:55 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/17 04:16:11 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

char	*ft_strdup_file(char *filename, int size)
{
	char	buffer;
	int		i;
	char	*str;
	int		fd;

	buffer = 0;
	i = 0;
	str = malloc(size + 1);
	fd = open(filename, O_RDONLY);
	while (read(fd, &buffer, 1) > 0)
		str[i++] = buffer;
	str[i] = '\0';
	close(fd);
	return str;
}

void	ft_print_offset(int n, int i)
{
	const char *base;

	base = "0123456789abcdef";
	if (n / 16 > 0)
		ft_print_offset(n / 16, i + 1);
	else if (i < 8)
		while (++i <= 8)
			write(1, "0", 1);
	write(1, base + n % 16, 1);
}

void	ft_print_hex(char c, int i, int size)
{
	const char base[16] = "0123456789abcdef";

	if (i < size)
	{
		write(1, base + c / 16, 1);
		write(1, base + c % 16, 1);
		write(1, " ", 1);
	}
	else 
		write(1, "   ", 3);
	if ((i + 1) % 8 == 0)
		write(1, " ", 1);
}

void	ft_print_ascii(char c)
{
	if (c >= 32 && c <= 126) 
		write(1, &c, 1);
	else 
		write(1, ".", 1);
}
