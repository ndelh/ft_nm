/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:39:50 by ndelhota          #+#    #+#             */
/*   Updated: 2026/05/04 11:30:40 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "retrieve_symbols.h"

void	retrieve_section_name(t_data *data, t_current_nm *nm,
		t_symbol *current_symbol)
{
	void		*cursor;
	uint64_t	index;

	if (current_symbol->section_index >= nm->section_header_nb)
		return (nm_error(data, "corrupted stt section name range"));
	cursor = nm->map_begin + nm->section_header_offset
		+ (nm->section_header_size * current_symbol->section_index);
	index = ((Elf64_Shdr *)cursor)->sh_name;
	if (index >= nm->shstr_content_size)
		return (nm_error(data, "corrupted stt section name range"));
	current_symbol->name = ft_strdup(nm->header_name + index);
}

void	assign_name(t_data *data, t_current_nm *nm, t_symbol *current_symbol)
{
	if (current_symbol->type_info == STT_SECTION)
		retrieve_section_name(data, nm, current_symbol);
	else
		current_symbol->name = ft_strdup(nm->sym_name
				+ current_symbol->name_index);
	if (!current_symbol->name)
		return (nm_error(data, "failed alloc when tying to dup sym_name"));
}
