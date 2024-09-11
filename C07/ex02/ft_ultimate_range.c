/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:37:48 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/06 12:36:56 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*buffer;
	int	buf_idx;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	buffer = (int *)malloc(sizeof(int) * (max - min + 1));
	if (!buffer)
		return (-1);
	buf_idx = 0;
	while (min < max)
		buffer[buf_idx++] = min++;
	*range = buffer;
	return (buf_idx);
}
