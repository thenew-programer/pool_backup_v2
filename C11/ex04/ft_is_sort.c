/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:09:55 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/16 14:14:00 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int lenght, int (*f)(int, int))
{
	int		i;
	int		end;
	int		start;

	i = 0;
	end = 0;
	start = 0;
	while (i < lenght - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) >= 0)
			end++;
		if ((*f)(tab[i], tab[i + 1]) <= 0)
			start++;
		i++;
	}
	if (start == i || end == i)
		return (1);
	return (0);
}
