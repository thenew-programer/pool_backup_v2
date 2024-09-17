/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:24:52 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/16 19:16:27 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <errno.h>
# include <unistd.h>
# include <fcntl.h>

# define M_STDIN 1
# define M_FILE 2

long long		ft_atoi(char *str);
void			ft_tail_error(char *input);
void			ft_tail_header(char *filename);
void			ft_putstr(char *str);
void			ft_putchar(char c);
void			read_file(int fd, long long size, long long bytes, int mode);
int				open_file(char *filename);
void			ft_tail(int argc, char **filenames, long long bytes);

#endif /* FT_TAIL_H */
