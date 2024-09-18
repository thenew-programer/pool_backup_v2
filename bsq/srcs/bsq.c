/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:17:25 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/18 13:07:49 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	init_map_pref(t_map_pref *map_pref)
{
	map_pref->width = 0;
	map_pref->height = 0;
}

int	bsq(int size, char **filenames)
{
	int	i;
	char **map;
	t_map_pref map_pref;

	i = 1;
	while (i < size)
	{
		init_map_pref(&map_pref);
		map = file_to_map(filenames[i], &map_pref);
		if (map == NULL)
			ft_putstr("map Error\n");
		// print_map_pref(map_pref);
		print_map(map, map_pref);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
