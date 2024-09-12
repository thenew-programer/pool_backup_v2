/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:28:13 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/09 11:45:38 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strchar(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	len = 0;
	while (str[i])
	{
		j = i;
		while (ft_strchar(charset, str[i]) && str[i])
			i++;
		if (!ft_strchar(charset, str[i]) && str[i])
			len++;
		while (!ft_strchar(charset, str[i]) && str[i])
			i++;
	}
	return (len);
}

char	**ft_strscpy(char *str, char *charset, char **strs)
{
	int		i;
	int		j;
	int		word_len;
	int		buf_index;

	i = 0;
	word_len = 0;
	buf_index = 0;
	while (str[i] && strs[buf_index])
	{
		word_len = 0;
		while (ft_strchar(charset, str[i]) && str[i])
			i++;
		j = 0;
		while (!ft_strchar(charset, str[i]) && str[i])
			strs[buf_index][j++] = str[i++];
		strs[buf_index++][j] = '\0';
	}
	return (strs);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		len;
	int		i;
	int		word_len;
	int		buf_index;

	i = 0;
	len = word_count(str, charset);
	strs = (char **)malloc(sizeof(char *) * (len + 1));
	if (!strs || !str)
		return (NULL);
	strs[len] = 0;
	buf_index = 0;
	while (str[i] && buf_index < len)
	{
		word_len = 0;
		while (ft_strchar(charset, str[i]) && str[i])
			i++;
		while (!ft_strchar(charset, str[i]) && str[i++])
			word_len++;
		strs[buf_index++] = (char *)malloc(sizeof(char) * word_len);
	}
	return (ft_strscpy(str, charset, strs));
}
