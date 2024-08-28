/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:42:52 by ybouryal          #+#    #+#             */
/*   Updated: 2024/08/28 10:43:14 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define MAX 10

static	void	print_digit(int n)
{
	char	c;

	if (n < 0 || n >= 10)
		return ;
	c = n + '0';
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < MAX - 2)
	{
		j = i + 1;
		while (j < MAX - 1)
		{
			k = j + 1;
			while (k < MAX)
			{
				print_digit(i);
				print_digit(j);
				print_digit(k);
				if (k == MAX - 1 && j == MAX - 2 && i == MAX - 3)
					break ;
				write(1, ", ", 2);
				k++;
			}
			j++;
		}
		i++;
	}
}
