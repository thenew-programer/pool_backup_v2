/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:40:35 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/19 15:45:31 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puttab(int *tab)
{
	int	j;

	j = 0;
	while (tab[j] != -1)
		ft_putchar(tab[j++] + '0');
	ft_putchar('\n');
}
void	ft_print_combn(int n)
{
	int	tab[10];
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		tab[i] = i;
		i++;
	}
	tab[i] = -1;

	i = n - 1;
	while (i >= 0)
	{
		j = 0;
		while (tab[i] != 9)
		{
			ft_puttab(tab);
			tab[i--]++;
		}
	}
}

int main()
{
	ft_print_combn(4);
}
