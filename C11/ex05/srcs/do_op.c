/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:37:34 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/16 15:49:32 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	g_error = 0;

t_calc	get_op(char *op, t_math *ops)
{
	int	i;

	i = 0;
	while (ops[i].op != 0)
	{
		if (ops[i].op == op[0])
			return (ops[i].calc);
		i++;
	}
	g_error = INVALID_OP;
	return (0);
}

int	check_error(void)
{
	if (g_error == INVALID_OP)
	{
		ft_putstr("operator is not working\n");
		return (-1);
	}
	if (g_error == INVALID_NB)
	{
		ft_putstr("numbers are not working\n");
		return (-1);
	}
	if (g_error == DIV_BY_0)
	{
		ft_putstr("Stop : division by zero\n");
		return (-1);
	}
	if (g_error == MOD_BY_0)
	{
		ft_putstr("Stop : division by zero\n");
		return (-1);
	}
	return (1);
}

void	do_op(char *nb1, char *op, char *nb2)
{
	int		result;
	t_math	ops[6];
	int		nbr1;
	int		nbr2;
	t_calc	calc;

	ops[0] = (t_math){'+', add};
	ops[1] = (t_math){'-', sub};
	ops[2] = (t_math){'*', mul};
	ops[3] = (t_math){'/', div};
	ops[4] = (t_math){'%', mod};
	ops[5] = (t_math){0, 0};
	nbr1 = ft_atoi(nb1);
	nbr2 = ft_atoi(nb2);
	if (check_error() == -1)
		return ;
	calc = get_op(op, ops);
	if (check_error() == -1)
		return ;
	result = (*calc)(nbr1, nbr2);
	if (check_error() == -1)
		return ;
	ft_putnbr(result);
	ft_putchar('\n');
}
