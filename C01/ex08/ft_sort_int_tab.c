/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 05:19:57 by ybouryal          #+#    #+#             */
/*   Updated: 2024/08/29 05:21:38 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	*a += *b;
	*b = *a - *b;
	*a = *a - *b;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap((tab + i), (tab + j));
			j++;
		}
		i++;
	}
}
