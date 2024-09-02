/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:13:17 by ybouryal          #+#    #+#             */
/*   Updated: 2024/08/31 19:13:25 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print(char f_char, char m_char, char l_char, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar(f_char);
		else if (i == x - 1)
			ft_putchar(l_char);
		else
			ft_putchar(m_char);
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	j;

	if (x < 0 || y < 0)
	{
		write(2, "Ho Ho How, we don't accept negatives in geometry\n", 49);
		return ;
	}
	if (x == 0 || y == 0)
	{
		write(2, "Oh common now. don't use 0 because it represent nothing.\n",
			57);
		return ;
	}
	j = 0;
	while (j < y)
	{
		if (j == 0)
			print('A', 'B', 'C', x);
		else if (j == y - 1)
			print('C', 'B', 'A', x);
		else
			print('B', ' ', 'B', x);
		j++;
	}
}
