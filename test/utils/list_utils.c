/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:36:19 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/28 16:20:59 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

void	insert_last(t_test **list, t_test *insert)
{
	t_test	*cursor;

	if (!list)
		return ;
	if (!*list)
	{
		*list = insert;
		return ;
	}
	cursor = *list;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = insert;
}

void	free_list(t_test *list)
{
	t_test	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->prog_args);
		free(tmp);
	}
}
