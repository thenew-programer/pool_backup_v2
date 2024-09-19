/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileIO.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:07:47 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/19 04:27:09 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

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

void	read_pref(int fd, t_map_pref *map_pref)
{
	int		i;
	int		j;
	char	buffer[10];

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
}

int	get_map_preference(char *filename, t_map_pref *map_pref)
{
	int		fd;
	char	c;

	fd = open_file(filename, map_pref);
	if (fd == -1)
		return (-1);
	read_pref(fd, map_pref);
	while (read(fd, &c, 1) > 0)
	{
		map_pref->width++;
		if (c == '\n')
			break ;
	}
	return (fd);
}

int	is_map_valid(int fd, t_map_pref *map_pref)
{
	char	c;
	int		tmp_height;
	int		tmp_width;

	tmp_width = 0;
	tmp_height = 1;
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
	if (tmp_height == map_pref->height && tmp_width == 0)
		return (1);
	return (0);
}

void	read_stdin(char *filename)
{
	char	buffer[4096];
	int		i;
	int		fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	i = 0;
	while ((read(0, &buffer[i], 1)) > 0)
	{
		write(fd, &buffer[i], 1);
		i++;
	}
	close(fd);
}
