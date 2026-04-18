/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:34:15 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/18 19:41:57 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "seek_symbols.h"

t_symbol	*gen(char c, char *s, uint64_t value)
{
	t_symbol	*to_ret;

	to_ret = malloc(sizeof(t_symbol));
	if (!to_ret)
	{
			print_simple_error("allocation failed during linked list creation");
			return (NULL);
	}
	to_ret->value = value;
	to_ret->name = s;
	to_ret->symbol = c;
	to_ret->next = NULL;
	return (to_ret);
}

void	list_add(t_nm *nm, char c, char *s, uint64_t value)
{
	t_symbol	*new_node;

	new_node = gen(c, s, value);
	if (!new_node)
		return ;
	if (nm->print_list)
		new_node->next = nm->print_list;
	nm->print_list = new_node;
}
