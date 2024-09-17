/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:31:17 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/17 21:35:58 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	int		index;

	if (nbr < 0 || !begin_list)
		return (0);
	index = 0;
	while (begin_list->next)
	{
		if (index == nbr)
			return (begin_list);
		begin_list = begin_list->next;
		index++;
	}
	if (nbr > index)
		return (begin_list);
	return (0);
}
