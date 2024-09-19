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
#include <sys/fcntl.h>

int	open_file(char *filename, t_map_pref *map_pref)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 3)
	{
		ft_putstr("bsq : ");
		ft_putstr(filename);
		ft_putstr(": No such file or directory\n");
		map_pref->errors = IO_ERROR;
		return (-1);
	}
	return (fd);
}

int	get_map_preference(char *filename, t_map_pref *map_pref)
{
	int		fd;
	char	buffer[10];
	char	c;
	int		i;
	int		j;

	fd = open_file(filename, map_pref);
	if (fd == -1)
		return (-1);
	i = 0;
	while (read(fd, &buffer[i], 1) > 0)
	{
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	i--;
	map_pref->full = buffer[i--];
	map_pref->obstacle = buffer[i--];
	map_pref->empty = buffer[i];
	j = 0;
	while (j < i)
		map_pref->height = (map_pref->height * 10) + (buffer[j++] - '0');

	// while (read(fd, &c, 1) > 0)
	// {
	// 	if (c >= '0' && c <= '9')
	// 		map_pref->height = (map_pref->height * 10) + (c - '0');
	// 	else
	// 	{
	// 		map_pref->empty = c;
	// 		break ;
	// 	}
	// }
	// read(fd, &map_pref->obstacle, 1);
	// read(fd, &map_pref->full, 1);
	// read(fd, &c, 1);
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

void	read_stdin(char *filename)
{
	char	buffer[10000];
	int		i;
	int		fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC);
	i = 0;
	while ((read(0, &buffer[i], 1)) > 0)
		i++;
	write(fd, buffer, i);
	close(fd);
}
