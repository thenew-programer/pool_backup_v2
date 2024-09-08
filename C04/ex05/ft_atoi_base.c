/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:03:45 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/08 13:44:21 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TRUE 1
#define FALSE 0
#define ERROR -1

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\f' || c == '\v')
		return (TRUE);
	return (FALSE);
}

int	is_base_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i + 1])
	{
		if (is_space(base[i]) || base[i] == '+' || base[i] == '-')
			return (ERROR);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (ERROR);
			if (is_space(base[j]) || base[j] == '+' || base[j] == '-')
				return (ERROR);
			j++;
		}
		i++;
	}
	return (i + 1);
}

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

int	_atoi_base(char *str, char *base, int index, int base_len)
{
	int	tmp;
	int	result;

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

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	m_sign;
	int	result;
	int	base_len;

	result = 0;
	base_len = is_base_valid(base);
	if (base_len == ERROR || base_len < 2)
		return (result);
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
