/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:36:07 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/01 10:57:23 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * ft_strstr - find a substring in a string using naive pattern searching
 * algorigthm
 *
 * @str: pointer to the haystack
 * @to_find: pointer to the needle
 *
 * Return: pointer to the first letter of the needle in haystack
*/
char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	pat_len;

	i = 0;
	pat_len = ft_strlen(to_find);
	if (pat_len == 0)
		return (str);
	while (str[i])
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (j == pat_len - 1)
				return ((char *)str + i);
			j++;
		}
		i++;
	}
	return (0);
}
