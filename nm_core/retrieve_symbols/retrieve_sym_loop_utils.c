/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_sym_loop_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:55:08 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/23 20:03:40 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "retrieve_symbols.h"

int	alloc_print_node(t_data *data, t_current_nm *nm)
{
	nm->current = malloc(sizeof(t_symbol));
	if (!nm->current)
	{
		nm_error(data, "malloc failed when forging symbol list");
		return (1);
	}
	return (0);
}

void	parse_print_intels(t_data *data, t_current_nm *nm, t_symbol *current)
{
	if (data->dead_nm)
		return ;
	if 	(current->name_index >= nm->str_sym_name_size)
		return (nm_error(data, "corrupted symtab name intels"));
	if (current->section_index >= nm->section_header_nb)
		return (nm_error(data, "corrupted symtab shndx"));
}

