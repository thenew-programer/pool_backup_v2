/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:35:52 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/16 17:51:51 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	int	ret;

	if (argc == 1)
	{
		read_file(1);
		return (0);
	}
	ret = ft_cat(argc, argv);
	return (ret);
}
