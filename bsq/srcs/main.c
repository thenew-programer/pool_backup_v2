/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:15:28 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/19 04:24:39 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	char	**tmp_file;

	if (argc == 1)
	{
		tmp_file = malloc(sizeof(char *) * 2);
		tmp_file[1] = "/tmp/abdo.txt";
		read_stdin("/tmp/abdo.txt");
		bsq(2, tmp_file);
		free(tmp_file);
	}
	else
		return (bsq(argc, argv));
	return (0);
}
