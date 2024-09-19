/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:38:16 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/19 04:23:04 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	tri_min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	else
		return (c);
}

void	find_square_position(int **dpm, t_map_pref *map_pref)
{
	int	i;
	int	j;

	i = 1;
	while (i < map_pref->height)
	{
		j = 1;
		while (j < map_pref->width)
		{
			if (dpm[i][j] == map_pref->dpm_max)
			{
				map_pref->square_x = i;
				map_pref->square_y = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

char	**solve(char **map, t_map_pref *map_pref)
{
	int	i;
	int	j;

	if (map_pref->square_y == 0 && map_pref->square_x == 0)
	{
		map_pref->square_y = map_pref->dpm_max;
		map_pref->square_x = map_pref->dpm_max;
	}
	i = map_pref->square_x - map_pref->dpm_max;
	while (i < map_pref->square_x)
	{
		j = map_pref->square_y - map_pref->dpm_max;
		while (j < map_pref->square_y)
		{
			map[i][j] = map_pref->full;
			j++;
		}
		i++;
	}
	return (map);
}
