/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileIO.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:07:47 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/18 13:13:54 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 3)
	{
		ft_putstr("bsq : ");
		ft_putstr(filename);
		ft_putstr(": No such file or directory\n");
		return (-1);
	}
	return (fd);
}

int	get_map_preference(char *filename, t_map_pref *map_pref)
{
	int		fd;
	char	c;

	fd = open_file(filename);
	if (fd == -1)
		return (-1);
	while (read(fd, &c, 1) > 0)
	{
		if (c >= '0' && c <= '9')
			map_pref->height = (map_pref->height * 10) + (c - '0');
		else
		{
			map_pref->empty = c;
			break ;
		}
	}
	read(fd, &map_pref->obstacle, 1);
	read(fd, &map_pref->full, 1);
	read(fd, &c, 1);
	while (read(fd, &c, 1) > 0)
	{
		map_pref->width++;
		if (c == '\n')
			break;
	}
	return (fd);
}

int	is_map_valid(int fd, t_map_pref *map_pref)
{
	char	c;
	int		tmp_height;
	int		tmp_width;

	tmp_width = 0;
	tmp_height = 0;
	while (read(fd, &c, 1) > 0)
	{
		tmp_width++;
		if (c == '\n' && tmp_width == map_pref->width)
		{
			tmp_height++;
			tmp_width = 0;
		}
	}
	close(fd);
	if (tmp_height + 1 == map_pref->height && tmp_width == 0)
		return (1);
	return (0);
}

void	read_stdin(void)
{
	char	c;

	while (read(1, &c, 1) > 0)
		;;
}
