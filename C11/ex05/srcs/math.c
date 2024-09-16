/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:51:15 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/16 16:01:05 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	add(int n1, int n2)
{
	return (n1 + n2);
}

int	sub(int n1, int n2)
{
	return (n1 - n2);
}

int	div(int n1, int n2)
{
	if (n2 == 0)
	{
		g_error = DIV_BY_0;
		return (0);
	}
	return (n1 / n2);
}

int	mul(int n1, int n2)
{
	return (n1 * n2);
}

int	mod(int n1, int n2)
{
	if (n2 == 0)
	{
		g_error = MOD_BY_0;
		return (0);
	}
	return (n1 % n2);
}
