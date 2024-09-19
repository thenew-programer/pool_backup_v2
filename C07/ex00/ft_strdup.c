/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:57:48 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/06 12:36:42 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		src_len;

	src_len = ft_strlen(src);
	dest = (char *)malloc((sizeof(char) * src_len) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < src_len + 1)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
