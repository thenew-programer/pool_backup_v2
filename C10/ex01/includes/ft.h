/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:31:53 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/16 17:48:30 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>

void	read_file(int fd);
int		open_file(char *filename);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_cat_error(char *filename);
int		ft_cat(int size, char **filenames);

#endif /* FT_H */
