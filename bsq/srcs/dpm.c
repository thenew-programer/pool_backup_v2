/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 04:20:42 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/19 04:22:30 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**init_dpm(int **dpm, t_map_pref *map_pref)
{
	int	i;

	i = 0;
	while (i <= map_pref->height)
	{
		dpm[i][0] = 0;
		i++;
	}
	i = 0;
	while (i < map_pref->width)
	{
		dpm[0][i] = 0;
		i++;
	}
	return (dpm);
}

int	**fill_dpm(char **map, int **dpm, t_map_pref *map_pref)
{
	int	i;
	int	j;

	i = 1;
	while (i <= map_pref->height)
	{
		j = 1;
		while (j < map_pref->width)
		{
			if (map[i - 1][j - 1] == map_pref->obstacle)
				dpm[i][j] = 0;
			else
				dpm[i][j] = tri_min(dpm[i - 1][j], dpm[i][j - 1],
						dpm[i - 1][j - 1]) + 1;
			if (dpm[i][j] > map_pref->dpm_max)
				map_pref->dpm_max = dpm[i][j];
			j++;
		}
		i++;
	}
	return (dpm);
}

int	**map_to_dpm(char **map, t_map_pref *map_pref)
{
	int	**dpm;
	int	i;

	dpm = (int **)malloc(sizeof(int *) * (map_pref->height + 1));
	i = 0;
	while (i <= map_pref->height)
	{
		dpm[i] = (int *)malloc(sizeof(int) * (map_pref->width + 1));
		i++;
	}
	init_dpm(dpm, map_pref);
	fill_dpm(map, dpm, map_pref);
	find_square_position(dpm, map_pref);
	return (dpm);
}

int	**print_dpm(int **dpm, t_map_pref *map_pref)
{
	int	i;
	int	j;

	i = 0;
	ft_putstr("{\n");
	while (i <= map_pref->height)
	{
		ft_putstr("[ ");
		j = 0;
		while (j < map_pref->width)
		{
			ft_putchar(dpm[i][j] + '0');
			if (j != map_pref->width - 1)
				ft_putstr(", ");
			j++;
		}
		ft_putstr("]\n");
		i++;
	}
	ft_putstr("}\n");
	return (dpm);
}
