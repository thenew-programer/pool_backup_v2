/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:52:45 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/04 21:53:08 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TRUE 1
#define FALSE 0

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

/**
 * PSEUDO-CODE
 *
 * If number given is prime:
 * 		Return number given and exit
 *
 * 	ELSE:
 * 		Repeat until prime number is found
 * 			if the number is given return it.
 * 		
*/

int	ft_find_next_prime(int nb)
{
	if (nb < 0)
		nb = 1;
	while (ft_is_prime(nb) == FALSE)
		nb++;
	return (nb);
}
