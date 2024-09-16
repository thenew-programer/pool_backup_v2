/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:48:08 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/16 15:48:43 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr / 10)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + '0');
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
