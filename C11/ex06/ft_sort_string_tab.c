/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:15:17 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/16 14:21:03 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **ptr1, char **ptr2)
{
	char	*tmp;

	tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i + 1])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}
