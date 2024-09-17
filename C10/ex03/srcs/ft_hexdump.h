/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 04:16:23 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/17 04:17:55 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H


# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

void	ft_hexdump(char *str, int size);
int		get_file_size(char *filename);
char	*ft_strdup_file(char *filename, int size);
void	ft_print_offset(int n, int i);
void	ft_print_hex(char c, int i, int size);
void	ft_print_ascii(char c);

#endif
