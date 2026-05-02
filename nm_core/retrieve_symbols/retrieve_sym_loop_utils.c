/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_sym_loop_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:55:08 by ndelhota          #+#    #+#             */
/*   Updated: 2026/05/02 22:23:43 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "retrieve_symbols.h"

t_symbol	*alloc_node(t_data *data)
{
	t_symbol	*to_ret;

	to_ret = malloc(sizeof(t_symbol));
	if (!to_ret)
	{
		nm_error(data, "failed malloc while creating symbol list");
		return (NULL);
	}
	ft_memset(to_ret, 0, sizeof(t_symbol));
	return (to_ret);
}

void	parse_print_intels(t_data *data, t_current_nm *nm, t_symbol *current)
{
	if (data->dead_nm)
		return ;
	if (current->name_index >= nm->str_sym_name_size)
		return (nm_error(data, "corrupted symtab name intels"));
	if (current->section_index >= nm->section_header_nb
		&& current->section_index < SHN_LORESERVE)
		return (nm_error(data, "corrupted symtab shndx"));
}
