/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:30:13 by ybouryal          #+#    #+#             */
/*   Updated: 2024/08/29 16:01:40 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define TRUE 1
#define FALSE 0

int	is_non_printable(char c)
{
	if ((c >= 0 && c <= 31) || c == 127)
		return (TRUE);
	return (FALSE);
}

void	print_hex(char c)
{
	char	buffer[10];
	char	tmp;
	int		i;

	i = 0;
	while (c)
	{
		tmp = c % 16;
		if (tmp < 10)
			tmp += '0';
		else
			tmp += 'a' - 10;
		buffer[i++] = tmp;
		c /= 16;
	}
	if (i == 1)
		buffer[i++] = '0';
	buffer[i--] = '\0';
	while (i >= 0)
		write(1, &buffer[i--], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (is_non_printable(str[i]))
		{
			write(1, "\\", 1);
			print_hex(str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
