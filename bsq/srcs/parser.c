/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:20:41 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/18 13:31:25 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"


char	**fill_map(char **map, char *filename, t_map_pref map_pref)
{
	int		i;
	int		fd;
	char	c;


	fd = open_file(filename);
	if (fd == -1)
		return (NULL);
	while (read(fd, &c, 1) > 0)
		if (c == '\n')
			break ;
	i = 0;
	while (i < map_pref.height)
	{
		read(fd, map[i], map_pref.width);
		i++;
	}
	i = 0;
	while (i < map_pref.height)
	{
		map[i][map_pref.width - 1] = '\0';
		i++;
	}
	return (map);
}

char	**file_to_map(char *filename, t_map_pref *map_pref)
{
	char		**map;
	int			i;
	int			fd;

	fd = get_map_preference(filename, map_pref);
	if (fd == -1)
		return (NULL);
	if (is_map_valid(fd, map_pref) == 0)
		return (NULL);
	i = 0;
	map = (char **)malloc(sizeof(char *) * (map_pref->height));
	while (i < map_pref->height)
	{
		map[i] = (char *)malloc(sizeof(char) * (map_pref->width));
		i++;
	}
	map = fill_map(map, filename, *map_pref);
	return (map);
}

void	print_map(char **map, t_map_pref pref)
{
	int	i;

	i = 0;
	while (i < pref.height)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

void	print_map_pref(t_map_pref pref)
{
	printf("pref->height: %d\n", pref.height);
	printf("pref->width: %d\n", pref.width);
	printf("pref->obstacle: %c\n", pref.obstacle);
	printf("pref->empty: %c\n", pref.empty);
	printf("pref->full: %c\n", pref.full);
}
