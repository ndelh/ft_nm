/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_sym_loop_32.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:23:54 by ndelhota          #+#    #+#             */
/*   Updated: 2026/05/01 15:24:21 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "retrieve_symbols.h"

void	retrieve_print_intels_32(t_data *data, t_current_nm *nm, Elf32_Sym *cursor)
{
	t_symbol *current_sym;
	
	current_sym = alloc_node(data);
	if (!current_sym)
		return (nm_error(data, "failed to allocate symbol node"));
	nm->current = current_sym;
	current_sym->name_index = cursor->st_name;
	current_sym->value = cursor->st_value;
	current_sym->type_info = cursor->st_info;
	current_sym->sym_size = cursor->st_size;
	current_sym->section_index = cursor->st_shndx;
}

void	retrieve_sym_loop_32(t_data *data, t_current_nm *nm)
{
	uint32_t	iteration;
	void		*cursor;

	if (data->dead_nm)
		return ;
	if (nm->symtab_content_size % nm->symstruct_size ||
		nm->symstruct_size != sizeof(Elf32_Sym))
		return (nm_error(data, "corrupted sym section size"));
	cursor = nm->map_begin + nm->symtab_content_offset;
	iteration = nm->symtab_content_size / sizeof(Elf32_Sym);
	cursor += nm->symstruct_size;
	--iteration;
	while (iteration && !data->dead_nm)
	{
		retrieve_print_intels_32(data, nm, (Elf32_Sym *)cursor);
		parse_print_intels(data, nm, nm->current);
		add_list(data, nm);
		--iteration;
		cursor += nm->symstruct_size;
	}
}
