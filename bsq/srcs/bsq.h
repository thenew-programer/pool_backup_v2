/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:08:28 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/18 13:11:06 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_map_pref
{
	int		height;
	int		width;
	char	obstacle;
	char	empty;
	char	full;
}	t_map_pref;

/* File IO */
int		open_file(char *filename);
void	read_stdin(void);
int		is_map_valid(int fd, t_map_pref *map_pref);
int		get_map_preference(char *filename, t_map_pref *map_pref);

/* Utils */
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	free_map(void **map, int size);

/* BSQ */
int	bsq(int size, char **filenames);
char	**file_to_map(char *filename, t_map_pref *pref);
char	**fill_map(char **map, char *filename, t_map_pref map_pref);
void	print_map(char **map, t_map_pref pref);
void	print_map_pref(t_map_pref pref);

#endif
