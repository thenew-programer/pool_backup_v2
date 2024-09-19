/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:15:28 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/18 12:16:08 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	char	**tmp_file;

	tmp_file = malloc(sizeof(char *) * 2);
	tmp_file[1] = "/tmp/bsq.txt";
	if (argc == 1)
	{
		read_stdin(tmp_file[1]);
		bsq(2, tmp_file);
	}
	else
		return (bsq(argc, argv));
	return (0);
}
