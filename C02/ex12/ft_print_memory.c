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

char	*content_to_hex(unsigned char nbr, char *buffer)
{
	unsigned char		i;
	unsigned char		tmp;

	i = 0;
	while (nbr)
	{
		tmp = nbr % 16;
		if (tmp < 10)
			tmp += '0';
		else
			tmp += 'a' - 10;
		buffer[i++] = (char)tmp;
		nbr /= 16;
	}
	buffer[i] = '\0';
	return (buffer);
}

void	print_content_hex(char *str, int size)
{
	int		i;
	char	buffer[3];
	int		spaces_left;

	i = 0;
	while (i < size)
	{
		if (i % 2 == 0 && i != 0)
			write(1, " ", 1);
		content_to_hex((unsigned char)(str[i]), buffer);
		write(1, &buffer[1], 1);
		write(1, &buffer[0], 1);
		i++;
	}
	write(1, " ", 1);
	if (size < ADDR_OFFSET)
	{
		i = 0;
		spaces_left = (8 - (size / 2)) +
		((ADDR_OFFSET - size + (size % 2)) * 2);
		i = 0;
		if (size % 2 != 1)
			spaces_left += 2;
		while (i < spaces_left)
		{
			write(1, " ", 1);
			i++;
		}

	}
}

void	print_content_str(char *str, int size)
{
	int		i;

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

char	*addr_hex(unsigned long bytes, char *buffer)
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
	while (buffer[i] && i >= 0)
		write(1, &buffer[i--], 1);
	return (buffer);
}

void	print_addr(void *addr)
{
	unsigned long	bytes;
	char			buffer[100];

	bytes = (unsigned long)addr;
	addr_hex(bytes, buffer);
	write(1, ": ", 2);
}

void	align(unsigned int size, int remainder)
{
		int	spaces_left;
		int	i;

		size = 0;
		spaces_left = (8 - (remainder / 2)) +
		((ADDR_OFFSET - remainder + (remainder % 2)) * 2);
		i = 0;
		if (remainder % 2 != 1)
			spaces_left += 2;
		while (i < spaces_left)
		{
			write(1, " ", 1);
			i++;
		}
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
	while (i < iterations)
	{
		print_addr(addr + (i * 16));
		print_content_hex((char *)addr + (i * 16), ADDR_OFFSET);
		print_content_str((char *)addr + (i * 16), ADDR_OFFSET);
		i++;
	}
	if (iterations * 16 == size)
	{
		print_addr(addr + (size - remainder));
		print_content_hex((char *)addr + (size - remainder), remainder);
		align(size, remainder);
		print_content_str((char *)addr + (size - remainder), remainder);
	}
	return (addr);
}

int main()
{
	char str[] = "hello world\0 how are u doing today.";
	ft_print_memory(str, sizeof(str));
}
