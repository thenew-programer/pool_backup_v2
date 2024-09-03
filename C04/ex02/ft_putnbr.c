/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 07:02:45 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/03 07:19:36 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define INT_MIN -2147483648

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == INT_MIN)
		{
			ft_putchar('2');
			nb = -147483648;
		}
		nb *= -1;
	}
	if (nb / 10)
		ft_putnbr(nb / 10);
	ft_putchar((char)(nb % 10 + '0'));
}
