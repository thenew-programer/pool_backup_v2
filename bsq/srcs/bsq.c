/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:17:25 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/19 04:28:40 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	init_map_pref(t_map_pref *map_pref)
{
	map_pref->errors = MAP_ERROR;
	map_pref->width = 0;
	map_pref->height = 0;
	map_pref->dpm_max = 0;
	map_pref->square_x = 0;
	map_pref->square_y = 0;
}

int	bsq(int size, char **filenames)
{
	int			i;
	char		**map;
	int			**dpm;
	t_map_pref	map_pref;

	i = 0;
	while (++i < size)
	{
		init_map_pref(&map_pref);
		map = file_to_map(filenames[i], &map_pref);
		if (map == NULL)
		{
			if (map_pref.errors == MAP_ERROR)
				ft_putstr("map Error\n");
			continue ;
		}
		dpm = map_to_dpm(map, &map_pref);
		map = solve(map, &map_pref);
		print_map(map, map_pref);
		free_map((void *)dpm, map_pref.height + 1);
		free_map((void *)map, map_pref.height);
	}
	return (0);
}
