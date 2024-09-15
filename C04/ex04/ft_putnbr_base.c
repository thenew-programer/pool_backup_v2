/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:44:50 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/03 19:25:11 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define TRUE 1
#define FALSE 0
#define C_INT_MIN -2147483648

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_duplicate(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i + 1] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[j] == str[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * base is valid: if size is equal or less than 1
 * base is valid: if it does not take duplicate chars
 * base is valid: if it contains '+' or '-'
 */
int	is_base_valid(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+'
			|| (base[i] > 0 && base[i] <= 32) || base[i] == 127)
		{
			return (0);
		}
		i++;
	}
	if (i < 2)
	{
		return (0);
	}
	if (is_duplicate(base) == 1)
	{
		return (0);
	}
	return (1);
}

void	convert_base(int nbr, char *base, int base_len)
{
	if (nbr == C_INT_MIN)
	{
		ft_putchar('-');
		convert_base(-(nbr / base_len), base, base_len);
		convert_base(-(nbr % base_len), base, base_len);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr / base_len)
		convert_base(nbr / base_len, base, base_len);
	ft_putchar(base[nbr % base_len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = 0;
	if (is_base_valid(base) == 0)
		return ;
	while (base[base_len] != '\0')
		base_len++;
	convert_base(nbr, base, base_len);
}
