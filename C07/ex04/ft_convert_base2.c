/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:41:25 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/11 15:34:10 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TRUE 1
#define FALSE 0
#define ERROR -1

int	g_buf_index = 0;

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

void	_convert_base(long long nbr, char *base, int base_len, char *buffer)
{
	if (nbr < 0)
	{
		buffer[g_buf_index++] = '-';
		nbr *= -1;
	}
	if (nbr / base_len)
		_convert_base(nbr / base_len, base, base_len, buffer);
	buffer[g_buf_index++] = base[nbr % base_len];
}

char	*convert_base(long long nbr, char *base, char *buffer)
{
	int	base_len;

	base_len = is_base_valid(base);
	while (base[base_len] != '\0')
		base_len++;
	_convert_base(nbr, base, base_len, buffer);
	buffer[g_buf_index] = '\0';
	g_buf_index = 0;
	return (buffer);
}
