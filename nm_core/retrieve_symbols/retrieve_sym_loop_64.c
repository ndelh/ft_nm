/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_sym_loop_64.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:40:45 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/23 18:48:08 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "retrieve_symbols.h"

void	retrieve_print_intels_64(t_data *data, t_current_nm *nm, Elf64_Sym *cursor)
{
	t_symbol *current_sym;
	
	if (alloc_print_node)
		return ;
	current_sym = nm->current;
	current_sym->name_index = cursor->st_name;
	current_sym->value = cursor->st_value;
	current_sym->type_info = cursor->st_info;
	current_sym->sym_size = cursor->st_size;
	current_sym->section_index = cursor->st_shndx;
}

void	retrieve_sym_loop_64(t_data *data, t_current_nm *nm)
{
	uint64_t	iteration;
	void		*cursor;

	if (data->dead_nm)
		return ;
	if (nm->symtab_content_size % nm->symstruct_size ||
		nm->symstruct_size != sizeof(Elf64_Sym))
		return (nm_error(data, "corrupted sym section size"));
	cursor = nm->map_begin + nm->symtab_content_offset;
	iteration = nm->symtab_content_size / sizeof(Elf64_Sym);
	cursor += nm->symstruct_size;
	--iteration;
	while (iteration && !data->dead_nm)
	{
		retrieve_print_intels_64(data, nm, (Elf64_Sym *)cursor);
		parse_print_intel(data, nm);
		add_list(data, nm);
		--iteration;
		cursor += nm->symstruct_size;
	}
}
