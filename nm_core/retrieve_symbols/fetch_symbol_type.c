/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 22:15:54 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/23 23:00:59 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "retrieve_symbols.h"

unsigned char	weak_case(uint16_t section_index, unsigned char info)
{
	if (ELF64_ST_TYPE(info) == STT_OBJECT)\
	{
		if (section_index == SHN_UNDEF)
			return ('v');
		else
			return ('V');
	}
	if (section_index == SHN_UNDEF)
		return ('w');
	return ('W');
}

unsigned char	is_special(uint16_t section_index, unsigned char info)
{	
	if (ELF64_ST_BIND(info) == STB_WEAK)
		return (weak_case(section_index, info));
	else if (section_index == SHN_UNDEF)
		return ('U');
	else if (section_index == SHN_ABS)
		return ('A');
	else if (section_index == SHN_COMMON)
		return ('C');
	return (0);
}

unsigned char	common_value(t_current_nm *nm, t_symbol *current)
{
	void	*indexed_shdr;

	indexed_shdr = nm->map_begin + nm->section_header_offset +
	(nm->section_header_size * current->section_index);
	if (nm->class == ELFCLASS32)
		return (assign_common_32((Elf32_Shdr *)indexed_shdr));
	else
		return (assign_common_64((Elf64_Shdr *)indexed_shdr));
}

unsigned char	assign_common(Elf64_Shdr *indexed_shdr)
{
	uint64_t flags;
	uint32_t type;

	type = indexed_shdr->sh_type;
	flags = indexed_shdr->sh_flags;
	if (type == SHT_NOBITS)
		return ('B');
	if (flags & SHF_EXECINSTR)
		return ('T');
	if (flags & SHF_WRITE)
		return ('D');
	if (flags & SHF_ALLOC)
		return ('R');
	else
		return ('N');
}

void	fetch_type(t_current_nm *nm, t_symbol *current)
{
	unsigned char	type;

	type = is_special(current->section_index, current->type_info);
	if (!type)
		type = common_value(nm, current);
	
	
}
