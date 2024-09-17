/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:21:26 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/17 21:27:08 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*head;
	int		i;

	head = ft_create_elem(strs[0]);
	i = 1;
	while (i < size)
	{
		ft_list_push_front(&head, strs[i]);
		i++;
	}
	return (head);
}
