/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:33:09 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/16 19:07:25 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_tail_header(char *filename)
{
	ft_putstr("==> ");
	ft_putstr(filename);
	ft_putstr(" <==\n");
}

void	ft_puterror(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(2, &str[i], 1);
}

void	ft_tail_error(char *input)
{
	ft_puterror("ft_tail: ");
	if (errno == 2)
	{
		ft_puterror("cannot open '");
		ft_puterror(input);
		ft_puterror("' for reading: No such file or directory\n");
	}
	else
	{
		ft_puterror("invalid number of bytes: '");
		ft_puterror(input);
		ft_puterror("'\n");
	}
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
