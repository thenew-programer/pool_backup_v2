/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:52:50 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/08 12:01:28 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#define TRUE 1
#define FALSE 0

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\f' || c == '\v')
		return (TRUE);
	return (FALSE);
}

int	ft_atoi(char *str)
{
	int		i;
	int		m_sign;
	long	result;

	i = 0;
	result = 0;
	m_sign = 0;
	while (is_space(str[i]) && str[i])
		i++;
	while ((str[i] == '+' || str[i] == '-') && str[i])
	{
		if (str[i] == '-')
			m_sign++;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
		result = (result * 10) + (str[i++] - '0');
	if (m_sign % 2)
		result *= -1;
	if (result < INT_MIN || result > INT_MAX)
		return (0);
	return ((int)result);
}
