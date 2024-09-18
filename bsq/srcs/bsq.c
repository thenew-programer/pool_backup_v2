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
	map_pref->errors = MAP_ERROR;
}

int	bsq(int size, char **filenames)
{
	int	i;
	char **map;
	int	**dpm;
	t_map_pref	map_pref;
	int			ret;

	ret = 0;
	i = 0;
	while (++i < size)
	{
		init_map_pref(&map_pref);
		map = file_to_map(filenames[i], &map_pref);
		if (map == NULL)
		{
			if (map_pref.errors == MAP_ERROR)
				ft_putstr("map Error\n");
			ret = 1;
			continue ;
		}
		dpm = map_to_dpm(map, &map_pref);
		print_dpm(dpm, &map_pref);
		print_map_pref(map_pref);
		map = solve(map, &map_pref);
		print_map(map, map_pref);
	}
	return (ret);
}
