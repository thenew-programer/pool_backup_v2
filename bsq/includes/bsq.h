/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:08:28 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/19 04:29:30 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define MAP_ERROR 2
# define IO_ERROR 3

typedef struct s_map_pref
{
	int		height;
	int		width;
	int		dpm_max;
	int		square_x;
	int		square_y;
	char	obstacle;
	char	empty;
	char	full;
	int		errors;
}	t_map_pref;

/* File IO */
int		open_file(char *filename, t_map_pref *map_pref);
void	read_stdin(char *filename);
int		is_map_valid(int fd, t_map_pref *map_pref);
int		get_map_preference(char *filename, t_map_pref *map_pref);

/* Utils */
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	free_map(void *map, int size);
int		is_printable(char c);
int		tri_min(int a, int b, int c);
void	ft_puterror(char *err);

/* BSQ */
int		bsq(int size, char **filenames);
char	**file_to_map(char *filename, t_map_pref *pref);
char	**fill_map(char **map, char *filename, t_map_pref *map_pref);
void	print_map(char **map, t_map_pref pref);
void	print_map_pref(t_map_pref pref);
void	init_map_pref(t_map_pref *map_pref);

/* Solver */
int		**map_to_dpm(char **map, t_map_pref *map_pref);
int		**init_dpm(int **dpm, t_map_pref *map_pref);
int		**print_dpm(int **dpm, t_map_pref *map_pref);
void	find_square_position(int **dpm, t_map_pref *map_pref);
int		**fill_dpm(char **map, int **dpm, t_map_pref *map_pref);
char	**solve(char **map, t_map_pref *map_pref);

#endif
