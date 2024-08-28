/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:01:02 by ybouryal          #+#    #+#             */
/*   Updated: 2024/08/28 14:31:19 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	ft_swap(char *c1, char *c2)
{
	char	tmp;

	tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

void	rev_str(char *str, int size)
{
	int		i;
	int		j;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		ft_swap(&str[i], &str[j]);
		i++;
		j--;
	}
}

char	*nbr_str(int n, char *buffer, int is_negative)
{
	int		buf_idx;

	buf_idx = 0;
	while (n)
	{
		buffer[buf_idx++] = '0' + (n % 10);
		n /= 10;
	}
	if (is_negative)
		buffer[buf_idx++] = '-';
	rev_str(buffer, buf_idx);
	buffer[buf_idx] = '\0';
	return (buffer);
}

void	ft_putnbr(int nb)
{
	int		is_negative;
	char	buffer[100];

	if (nb == -2147483648)
	{
		ft_putstr("-2");
		nb = 147483648;
	}
	is_negative = 0;
	if (nb < 0)
	{
		nb *= -1;
		is_negative = 1;
	}
	nbr_str(nb, buffer, is_negative);
	ft_putstr(buffer);
}
