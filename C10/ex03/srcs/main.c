/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 04:12:48 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/17 04:13:00 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	main(int argc, char **argv)
{
	char	*str;
	int		i;
	int		size;

	i = 0;
	while (++i < argc)
	{
		if (!(*argv[i] == '-' && *(argv[i] + 1) == 'C'))
		{
			size = get_file_size(argv[i]);
			str = ft_strdup_file(argv[i], size);
			ft_hexdump(str, size);
		}
	}
	return (0);
}
