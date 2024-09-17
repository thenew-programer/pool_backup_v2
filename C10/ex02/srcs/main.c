/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:35:52 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/16 19:05:46 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	main(int argc, char **argv)
{
	long long	bytes;
	int			i;

	if (argc < 4)
	{
		read_file(1, 0, 0, M_STDIN);
		return (0);
	}
	i = 0;
	bytes = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == 'c' && argv[i][2] == 0
			&& argc >= (i + 1))
		{
			bytes = ft_atoi(argv[i + 1]);
			if (bytes == -1)
				ft_tail_error(argv[i + 1]);
			break ;
		}
	}
	if (bytes != 0)
		ft_tail(argc, argv, bytes);
	return (0);
}
