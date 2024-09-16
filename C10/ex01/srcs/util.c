/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:33:09 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/16 17:40:11 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_puterror(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(2, &str[i], 1);
}

void	ft_cat_error(char *filename)
{
	ft_puterror("ft_cat: ");
	ft_puterror(filename);
	ft_puterror(": No such file or directory\n");
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}
