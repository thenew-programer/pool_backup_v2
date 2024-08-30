/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:58:56 by ybouryal          #+#    #+#             */
/*   Updated: 2024/08/29 12:05:40 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TRUE 1
#define FALSE 0

int	is_lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (TRUE);
	return (FALSE);
}

int	is_symbol(char c)
{
	if (c >= ' ' && c <= '/')
		return (TRUE);
	return (FALSE);
}

int	is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (TRUE);
	return (FALSE);
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	if (is_lowercase(str[0]))
		str[0] -= 32;
	i = 1;
	while (str[i])
	{
		if (is_symbol(str[i - 1]))
		{
			if (is_lowercase(str[i]))
				str[i] -= 32;
		}
		else
		{
			if (is_alpha(str[i]) && !is_lowercase(str[i]))
				str[i] += 32;
		}
		i++;
	}
	return (str);
}
