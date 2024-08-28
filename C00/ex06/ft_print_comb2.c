/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:43:39 by ybouryal          #+#    #+#             */
/*   Updated: 2024/08/28 14:27:57 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define MAX 9
#define RIGHT 1
#define LEFT 0

char	helper(int value, int place)
{
	if (place == RIGHT)
		return (char)(value / 10 + '0');
	return (char)(value % 10 + '0');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int		i;
	int		j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_putchar(helper(i, RIGHT));
			ft_putchar(helper(i, LEFT));
			ft_putchar(' ');
			ft_putchar(helper(j, RIGHT));
			ft_putchar(helper(j, LEFT));
			if (!(i == 98 && j == 99))
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
}

int main()
{
	ft_print_comb2();
}
