/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_symbol_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 22:15:54 by ndelhota          #+#    #+#             */
/*   Updated: 2026/05/02 22:15:36 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "retrieve_symbols.h"

unsigned char	weak_case(uint16_t section_index, unsigned char info)
{
	if (ELF64_ST_TYPE(info) == STT_OBJECT)
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

unsigned char	assign_common(t_current_nm *nm, Elf64_Shdr *indexed_shdr)
{
	nm->current->type = indexed_shdr->sh_type;
	if (nm->class == ELFCLASS64)
		nm->current->flags = indexed_shdr->sh_flags;
	else
		nm->current->flags = ((Elf32_Shdr *)indexed_shdr)->sh_flags;
	if (nm->current->type == SHT_NOBITS)
		return ('B');
	if (nm->current->flags & SHF_EXECINSTR)
		return ('T');
	if (nm->current->flags & SHF_WRITE)
		return ('D');
	if (nm->current->flags & SHF_ALLOC)
		return ('R');
	else
		return ('N');
}

unsigned char	common_value(t_current_nm *nm, t_symbol *current)
{
	void	*indexed_shdr;

	indexed_shdr = nm->map_begin + nm->section_header_offset
		+ (nm->section_header_size * current->section_index);
	return (assign_common(nm, (Elf64_Shdr *)indexed_shdr));
}

void	fetch_type(t_current_nm *nm, t_symbol *current)
{
	unsigned char	type;

	type = is_special(current->section_index, current->type_info);
	if (!type)
		type = common_value(nm, current);
	if (type != 'U' && ELF64_ST_BIND(current->type_info) == STB_LOCAL
		&& type != 'N')
		type = ft_tolower(type);
	current->symbol = type;
}
