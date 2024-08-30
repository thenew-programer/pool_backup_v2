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

void	put_rev_str(char *str, int size)
{
	int		i;

	i = 0;
	// while (size-- >= 0)
	// 	write(1, &str[size], 1);
	while (str[i])
		write(1, &str[i++], 1);
}

char	*dec_to_hex(unsigned long bytes, char *buffer)
{
	unsigned long	i;
	unsigned long	tmp;

	i = 0;
	while (bytes)
	{
		tmp = bytes % 16;
		if (tmp < 10)
			tmp += '0';
		else
			tmp += 'a' - 10;
		buffer[i++] = (char)tmp;
		bytes /= 16;
	}
	if (i < ADDR_OFFSET)
	{
		while (i < ADDR_OFFSET)
			buffer[i++] = '0';
	}
	buffer[i--] = '\0';
	// put_rev_str(buffer, (int)i);
	while (buffer[i] && i >= 0)
		write(1, &buffer[i--], 1);
	return (buffer);
}

void	print_addr(void *addr)
{
	unsigned long	bytes;
	char	buffer[100];

	bytes = (unsigned long)addr;
	dec_to_hex(bytes, buffer);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	iterations;
	unsigned int	remainder;
	unsigned int	i;

	if (size == 0)
		return (addr);
	iterations = size / 16;
	remainder = size % 16;
	i = 0;
	// while (i < iterations)
	// {
	// 	/**
	// 	 * print_address
	// 	 * Print_content in hex
	// 	 * print content
	// 	*/
	// 	i++;
	// }
	return (addr);
}

int main()
{
	char str[] = "HEllo world";

	print_addr((void *)str);
}
