/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 22:07:08 by ndelhota          #+#    #+#             */
/*   Updated: 2026/05/02 22:12:24 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "retrieve_symbols.h"

void	add_back(t_current_nm *nm)
{
	t_symbol	*list;

	list = nm->print_list;
	while (list->next)
		list = list->next;
	list->next = nm->current;
	nm->current->previous = list;
}
