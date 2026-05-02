/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 21:56:20 by ndelhota          #+#    #+#             */
/*   Updated: 2026/05/02 22:11:38 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "retrieve_symbols.h"

int64_t	tie_breaker(t_data *data, t_symbol *a, t_symbol *b)
{
	int64_t	to_ret;

	to_ret = nm_comp(a->name, b->name);
	if (data->flags & FLAG_R)
		to_ret *= -1;
	return (to_ret);
}

int	no_maj_cmp(t_data *data, char *s1, char *s2)
{
	unsigned char	a;
	unsigned char	b;

	a = 0;
	b = 0;
	while (*s1 || *s2)
	{
		while (*s1 && !ft_isalnum(*s1))
			++s1;
		while (*s2 && !ft_isalnum(*s2))
			++s2;
		if (ft_tolower(*s1) != ft_tolower(*s2) || !*s1 || !*s2)
			break ;
		++s1;
		++s2;
	}
	a = ft_tolower(*s1);
	b = ft_tolower(*s2);
	if (data->flags & FLAG_R)
		return (b - a);
	return (a - b);
}

int	insert_first(t_data *data, t_current_nm *nm, t_symbol *current)
{
	int64_t	comp;

	comp = no_maj_cmp(data, nm->print_list->name, current->name);
	if (!comp)
		comp = tie_breaker(data, nm->print_list, current);
	if (comp > 0)
	{
		current->next = nm->print_list;
		nm->print_list->previous = current;
		nm->print_list = current;
		return (1);
	}
	return (0);
}

void	insert_list(t_data *data, t_current_nm *nm, t_symbol *current)
{
	t_symbol	*list;
	int64_t		comp;

	list = nm->print_list;
	if (insert_first(data, nm, current))
		return ;
	while (list->next)
	{
		comp = no_maj_cmp(data, list->next->name, current->name);
		if (!comp)
			comp = tie_breaker(data, list->next, current);
		if (comp > 0)
			break ;
		list = list->next;
	}
	current->next = list->next;
	if (current->next)
		current->next->previous = current;
	current->previous = list;
	list->next = current;
}

void	add_list(t_data *data, t_current_nm *nm)
{
	fetch_type(nm, nm->current);
	assign_name(data, nm, nm->current);
	if (!nm->print_list)
		nm->print_list = nm->current;
	else if (data->flags & FLAG_P)
		add_back(nm);
	else
		insert_list(data, nm, nm->current);
	nm->current = NULL;
}
