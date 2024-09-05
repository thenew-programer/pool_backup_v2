/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:39:23 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/04 21:51:34 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TRUE 1
#define FALSE 0

/**
 * a prime number is a num that can be devided by itself
 * and one.
 * 0, 1 &  negatives are not prime numbers
 * to check if a number is prime u only need to check up
 * to square root of the number
*/
int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (FALSE);
	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
