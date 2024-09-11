/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:18:19 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/08 10:31:26 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned long	get_length(int size, char **strs, char *sep)
{
	unsigned long	len;
	int				i;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += (unsigned int)ft_strlen(strs[i]);
		i++;
	}
	len += (ft_strlen(sep) * (size - 1));
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	if (!src || src[0] == 0)
		return (0);
	while (src[j] && i < size - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + j + ft_strlen(src));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	unsigned long	len;
	char			*str;
	int				i;

	if (size == 0)
	{
		str = (char *)malloc(sizeof(char));
		*str = 0;
		return (str);
	}
	len = get_length(size, strs, sep);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	*str = 0;
	i = 0;
	while (i < size)
	{
		if (strs[i])
			ft_strlcat(str, strs[i], len + 1);
		if (i != size - 1 && sep)
			ft_strlcat(str, sep, len + 1);
		i++;
	}
	return (str);
}
