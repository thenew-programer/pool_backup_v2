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

void	init_ops(int (*ops[6])(int, int))
{
	ops[0] = add;
	ops[1] = sub;
	ops[2] = mul;
	ops[3] = div;
	ops[4] = mod;
}

int	do_op(char *nbr1, char *op, char *nbr2)
{
	int	(*ops[6])(int, int);
	int	operator;
	int	values[2];

	init_ops(ops);
	values[0] = ft_atoi(nbr1);
	values[1] = ft_atoi(nbr2);
	operator = check_op(op);
	if (operator == -1)
		ft_putstr("0\n");
	else if (operator == 3 && values[1] == 0)
		ft_putstr("Stop : division by zero\n");
	else if (operator == 4 && values[1] == 0)
		ft_putstr("Stop : modulo by zero\n");
	else
	{
		ft_putnbr(ops[operator](values[0], values[1]));
		ft_putstr("\n");
		return (0);
	}
	return (1);
}

int	check_op(char *op)
{
	int		i;
	char	*ops;

	ops = "+-*/%";
	i = 0;
	while (i < 5)
	{
		if (ops[i] == op[0] && op[1] == '\0')
			return (i);
		i++;
	}
	return (-1);
}
