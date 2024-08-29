/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 05:14:32 by ybouryal          #+#    #+#             */
/*   Updated: 2024/08/29 05:18:41 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	*a += *b;
	*b = *a - *b;
	*a = *a - *b;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int		i;
	int		j;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		ft_swap((tab + i), (tab + j));
		i++;
		j--;
	}
}
