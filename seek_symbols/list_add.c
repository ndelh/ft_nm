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

char	*fetch_cmp_value(char *s)
{
	while (*s && !ft_isalnum(*s))
		++s;
	return (s);
}

void	list_insert(t_symbol **list, t_symbol *new)
{
	t_symbol	*cursor;
	char		*new_name;
	char		*next_name;

	cursor = *list;
	new_name = fetch_cmp_value(new->name);
	next_name = fetch_cmp_value(cursor->name);
	if (no_maj_cmp(new_name, next_name) <= 0)
	{
		new->next = *list;
		*list = new;
		return ;
	}
	while (cursor->next)
	{
		next_name = fetch_cmp_value(cursor->next->name);
		if (no_maj_cmp(new_name, next_name) <= 0)
			break ;
		cursor = cursor->next;
	}
	new->next = cursor->next;
	cursor->next = new;
}

void	list_add(t_nm *nm, char c, char *s, uint64_t value)
{
	t_symbol	*new_node;

	if (!*s)
	{
		free(s);
		return ;
	}
	new_node = gen(c, s, value);
	if (!new_node)
		return ;
	if (!nm->print_list)
	{
		new_node->next = nm->print_list;
		nm->print_list = new_node;
	}
	else
		list_insert(&nm->print_list, new_node);
}
