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
#define INT_MIN -2147483648

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
			if (str[j] == str[i])
				return (TRUE);
		i++;
	}
	return (FALSE);
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
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (FALSE);
		i++;
	}
	if (i == 1)
		return (FALSE);
	if (is_duplicate(base))
		return (FALSE);
	return (TRUE);
}

void	convert_base(int nbr, char *base, int base_nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		if (nbr == INT_MIN)
		{
			ft_putchar(base[2]);
			nbr *= -147483648;
		}
	}
	if (nbr / 10)
		convert_base(nbr / base_nbr, base, base_nbr);
	ft_putchar(base[nbr % base_nbr]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = 0;
	if (!is_base_valid(base))
		return ;
	while (base[i])
		i++;
	convert_base(nbr, base, i);

	/**
	 * check if base is valid
	 *
	 * convert nbr to str of base
	*/
}

#include <unistd.h>
#include <limits.h>

void	ft_putnbr_base(int nbr, char *base);

int		main(void)
{
	write(1, "42:", 3);
	ft_putnbr_base(42, "0123456789");
	write(1, "\n2a:", 4);
	ft_putnbr_base(42, "0123456789abcdef");
	write(1, "\n-2a:", 5);
	ft_putnbr_base(-42, "0123456789abcdef");
	write(1, "\n0:", 3);
	ft_putnbr_base(0, "0123456789abcdef");
	write(1, "\nINT_MAX:", 9);
	ft_putnbr_base(INT_MAX, "0123456789abcdef");
	write(1, "\nINT_MAX:", 9);
	ft_putnbr_base(INT_MAX, "ZYXWVUTSRQPONMLKJIHGFEDCBAzyxwvutsrqponmlkjihgfedcba9876543210");
	write(1, "\nINT_MIN:", 9);
	ft_putnbr_base(INT_MIN, "0123456789abcdef");
	write(1, "\n-2143247366 : ", 15);
	ft_putnbr_base(INT_MIN + 4236282, "'~");
	write(1, "\n-1:", 4);
	ft_putnbr_base(-1, "0123456789abcdef");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "0");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "+-0123456789abcdef");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "\v0123456789abcdef");
}

