/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 02:56:52 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/10 03:04:08 by ybouryal         ###   ########.fr       */
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

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*stock;

	if (ac < 0 || !av || !*av)
		return (NULL);
	i = 0;
	stock = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * ac);
	if (!stock)
		return (NULL);
	while (i < ac)
	{
		stock[i].size = ft_strlen(av[i]);
		stock[i].str = ft_strdup(av[i]);
		stock[i].copy = ft_strdup(av[i]);
		i++;
	}
	return (stock);
}
/**
#include <stdio.h>
int main(int argc, char **argv)
{
	int	i;
	t_stock_str *stock;

	i = 0;
	stock = ft_strs_to_tab(argc, argv);
	while (i < argc)
	{
		printf("|\t{size}: %d\n", stock[i].size);
		printf("   -----{str}: %s\n", stock[i].str);
		printf("|\t{copy}: %s\n\n", stock[i].copy);
		i++;
	}
	i = 0;
	free(stock);
	return (0);
}*/
