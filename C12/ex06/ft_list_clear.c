/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:26:38 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/17 21:30:55 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*head;
	t_list	*tmp;

	head = begin_list;
	while (head->next)
	{
		tmp = head->next;
		free_fct(head->data);
		head = tmp;
	}
	free_fct(head);
}
