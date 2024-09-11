/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:07:52 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/05 20:18:14 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	buf_idx;

	if (min >= max)
		return (NULL);
	range = (int *)malloc(sizeof(int) * (max - min + 1));
	if (!range)
		return (NULL);
	buf_idx = 0;
	while (min < max)
		range[buf_idx++] = min++;
	return (range);
}
