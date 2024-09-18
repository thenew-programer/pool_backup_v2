/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:38:16 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/18 17:03:16 by ybouryal         ###   ########.fr       */
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

int	tri_min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return a;
	else if (b <= a && b <= c)
		return b;
	else
		return c;
}

int	**fill_dpm(char **map, int **dpm, t_map_pref *map_pref)
{
	int	i;
	int	j;

	map_pref->dpm_max = 0;
	i = 1;
	while (i <= map_pref->height)
	{
		j = 1;
		while (j < map_pref->width)
		{
			if (map[i - 1][j - 1] == map_pref->obstacle)
				dpm[i][j] = 0;
			else
				dpm[i][j] = tri_min(dpm[i - 1][j], dpm[i][j - 1], dpm[i - 1][j - 1]) + 1;
			if (dpm[i][j] > map_pref->dpm_max)
				map_pref->dpm_max = dpm[i][j];
			j++;
		}
		i++;
	}
	return (dpm);
}

void	find_square_position(int **dpm, t_map_pref *map_pref)
{
	int	i;
	int	j;

	i = 0;
	while (i <= map_pref->height)
	{
		j = 0;
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

int	**map_to_dpm(char **map, t_map_pref *map_pref)
{
	int	**dpm;
	int	i;

	dpm = (int **)malloc(sizeof(int *) * (map_pref->height + 1));
	i = 0;
	while (i <= map_pref->height)
	{
		dpm[i] = (int *)malloc(sizeof(int) * (map_pref->width));
		i++;
	}
	init_dpm(dpm, map_pref);
	fill_dpm(map, dpm, map_pref);
	find_square_position(dpm, map_pref);
	return (dpm);
}

char	**solve(char **map, t_map_pref *map_pref)
{
	int	i;
	int	j;

	i = map_pref->square_y - map_pref->dpm_max;
	while (i < map_pref->square_y)
	{
		j = map_pref->square_x - map_pref->dpm_max;
		while (j < map_pref->square_x)
		{
			map[i][j] = map_pref->full;
			j++;
		}
	i++;
	}
	return (map);
}

int	**print_dpm(int **dpm, t_map_pref *map_pref)
{
	int	i;
	int	j;

	i = 0;
	ft_putstr("{\n");
	while (i < map_pref->height + 1)
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
