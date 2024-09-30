/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:03:22 by ybouryal          #+#    #+#             */
/*   Updated: 2024/08/30 12:22:14 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define ADDR_OFFSET 16
#define TRUE 1
#define FALSE 0

void	addr_hex(unsigned long bytes)
{
	char			*base16;

	base16 = "0123456789abcdef";
	if (bytes / 16)
		addr_hex(bytes / 16);
	write(1, &base16[bytes % 16], 1);
}

void	print_content_hex(char *str, int size)
{
	int	i;
	int	spaces_left;

	i = 0;
	spaces_left = 0;
	if (size % 2 == 0)
		spaces_left--;
	while (i < size)
	{
		if (i % 2 == 0 && i != 0)
		{
			write(1, " ", 1);
			spaces_left++;
		}
		if (str[i] <= 16)
			write(1, "0", 1);
		addr_hex((unsigned long)str[i]);
		spaces_left += 2;
		i++;
	}
	spaces_left = 40 - spaces_left;
	i = -1;
	while (++i <= spaces_left)
		write(1, " ", 1);
	write(1, " ", 1);
}

void	print_content_str(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (str[i] >= ' ' && str[i] <= '~')
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	print_addr(void *addr)
{
	unsigned long	bytes;

	bytes = (unsigned long)addr;
	addr_hex(bytes);
	write(1, ": ", 2);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	iterations;
	unsigned int	remainder;
	unsigned int	i;

	if (size == 0)
		return (addr);
	iterations = size / ADDR_OFFSET;
	remainder = size % ADDR_OFFSET;
	i = 0;
	while (i < iterations)
	{
		print_addr(addr + (i * 16));
		print_content_hex((char *)addr + (i * 16), ADDR_OFFSET);
		print_content_str((char *)addr + (i * 16), ADDR_OFFSET);
		i++;
	}
	if (iterations * 16 != size)
	{
		print_addr(addr + (size - remainder));
		print_content_hex((char *)addr + (size - remainder), remainder);
		print_content_str((char *)addr + (size - remainder), remainder);
	}
	return (addr);
}
