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

int	check_div_mod(char *n1, char *n2, int ope, int *values)
{
	values[0] = ft_atoi(n1);
	values[1] = ft_atoi(n2);
	if (values[1] == 0 && ope == 3)
		ft_putstr("Stop : division by zero");
	else if (values[1] == 0 && ope == 4)
		ft_putstr("Stop : modulo by zero");
	else
		return (1);
	return (0);
}

int	do_op(char *nbr1, char *op, char *nbr2)
{
	t_math	ops[6];
	int		operator;
	int		values[2];

	ops[0] = (t_math){'+', add};
	ops[1] = (t_math){'-', add};
	ops[2] = (t_math){'*', add};
	ops[3] = (t_math){'/', add};
	ops[4] = (t_math){'%', add};
	operator = check_op(op, ops);
	if (operator != -1)
	{
		if (check_div_mod(nbr1, nbr2, operator, values) != 0)
			ft_putnbr(ops[operator].calc(values[0], values[1]));
		ft_putchar('\n');
		return (0);
	}
	else
	{
		ft_putnbr(0);
		ft_putchar('\n');
		return (operator);
	}
}

int	check_op(char *op, t_math *ops)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (ops[i].op == op[0] && op[1] == '\0')
			return (i);
		i++;
	}
	return (-1);
}
