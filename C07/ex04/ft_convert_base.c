/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:03:48 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/11 15:33:49 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define ERROR -1

char	*convert_base(long long nbr, char *base, char *buffer);
int		is_base_valid(char *base);
int		is_space(char c);

int	ft_strchar(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (ERROR);
}

long long	_atoi_base(char *str, char *base, int index, int base_len)
{
	int			tmp;
	long long	result;

	result = 0;
	while (str[index])
	{
		tmp = ft_strchar(base, str[index]);
		if (tmp == ERROR)
			break ;
		result = (result * base_len) + tmp;
		index++;
	}
	return (result);
}

long long	ft_atoi_base(char *str, char *base)
{
	int			i;
	int			m_sign;
	long long	result;
	int			base_len;

	result = 0;
	base_len = is_base_valid(base);
	i = 0;
	m_sign = 0;
	while (is_space(str[i]) && str[i])
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			m_sign++;
	result = _atoi_base(str, base, i, base_len);
	if (m_sign % 2)
		result *= -1;
	return (result);
}

int	get_num_len(long long nbr, char *base)
{
	int	base_len;
	int	num_len;

	num_len = 0;
	if (nbr < 0)
	{
		num_len = 1;
		nbr *= -1;
	}
	base_len = 0;
	while (base[base_len])
		base_len++;
	while (nbr)
	{
		nbr /= base_len;
		num_len++;
	}
	return (num_len++);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long		dec_nbr;
	char			*base_to_nbr;
	int				tmp;

	tmp = is_base_valid(base_from);
	if (tmp == ERROR || tmp < 2)
		return (NULL);
	tmp = is_base_valid(base_to);
	if (tmp == ERROR || tmp < 2)
		return (NULL);
	dec_nbr = ft_atoi_base(nbr, base_from);
	if (dec_nbr == ERROR)
		return (NULL);
	if (dec_nbr >= INT_MAX)
		dec_nbr = INT_MAX;
	if (dec_nbr <= INT_MIN)
		dec_nbr = INT_MIN;
	base_to_nbr = (char *)malloc(sizeof(char) * get_num_len(dec_nbr, base_to));
	if (!base_to_nbr)
		return (NULL);
	base_to_nbr = convert_base(dec_nbr, base_to, base_to_nbr);
	return (base_to_nbr);
}
/*
#include <stdio.h>
int main(void)
{
	char *nbr = "1337";
	char *base_10 = "0123456789";
	char *base_16 = "0123456789ABCDEF";
	char *base_8 = "01234567";
	char *base_2 = "01";
	char *base_5 = "01234";
	char *base_2_ = "'~";
	char *base_6 = "'/\"?!6";
	char *base_invalid = "1";

	printf("null : %s\n", ft_convert_base(nbr, base_10, base_invalid));
	printf("1337 : %s\n", ft_convert_base(nbr, base_10, base_10));
	printf("539 : %s\n", ft_convert_base(nbr, base_10, base_16));
	printf("2471 : %s\n", ft_convert_base(nbr, base_10, base_8));
	printf("10100111001 : %s\n", ft_convert_base(nbr, base_10, base_2));
	printf("~'~''~~~''~ : %s\n", ft_convert_base(nbr, base_10, base_2_));
	printf("20322 : %s\n", ft_convert_base(nbr, base_10, base_5));
	printf("/'/'6 : %s\n", ft_convert_base(nbr, base_10, base_6));
	return (0);
}
*/
