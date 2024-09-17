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

#define TRUE 1
#define FALSE 0

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		sorted;
	char	*tmp;

	sorted = FALSE;
	while (sorted == FALSE)
	{
		sorted = TRUE;
		i = -1;
		while (tab[++i + 1])
		{
			if ((*cmp)(tab[i], tab[i + 1]) > 0)
			{
				sorted = FALSE;
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
		}
	}
}
