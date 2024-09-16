/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:23:51 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/16 14:26:49 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **ptr1, char **ptr2)
{
	char	*tmp;

	tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = 0;
	while (tab[i + 1])
	{
		j = i + 1;
		while (tab[j])
		{
			if ((*cmp)(tab[i], tab[j]) > 0)
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}
