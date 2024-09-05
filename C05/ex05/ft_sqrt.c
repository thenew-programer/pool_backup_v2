/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_unfinished.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:32:21 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/04 21:39:06 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * PSEUDO-CODE:
 * if nb is negative:
 *		return 0
 * Repeat until  sqrt is bigger than OR equal number
 *		if  index square equals number
 *			return that number
 *
 * Otherwise
 *		Return 0
*/

int	ft_sqrt(int nb)
{
	int	sqrt;
	int	i;

	if (nb <= 0)
		return (0);
	i = 0;
	while (i <= nb)
	{
		sqrt = i * i;
		if (sqrt == nb)
			return (i);
		i++;
	}
	return (0);
}
