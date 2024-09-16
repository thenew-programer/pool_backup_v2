/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:32:01 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/16 15:09:16 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

# define INVALID_OP 10
# define INVALID_NB 11
# define DIV_BY_0 12
# define MOD_BY_0 13

extern int	g_error;

typedef int	(*t_calc)(int, int);

typedef struct s_math
{
	char	op;
	t_calc	calc;
}	t_math;

void	do_op(char *nb1, char *op, char *nb2);
void	ft_putnbr(int nbr);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
int		mod(int n1, int n2);
int		mul(int n1, int n2);
int		div(int n1, int n2);
int		add(int n1, int n2);
int		sub(int n1, int n2);

#endif /* DO_OP_H */
