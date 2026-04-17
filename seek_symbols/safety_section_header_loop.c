/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety_section_header_loop.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:13:00 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/17 12:25:29 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "seek_symbols.h"

int	parse_node_32(t_nm *nm, Elf32_Shdr *node)
{
	if (add_overflow(node->sh_offset, node->sh_size,
		"Error: section header content + size cause overflow"))
		return (1);
	if (is_offset_out(nm, node->sh_offset + node->sh_size,
		"Error: section content is atleast partially out of bound"))
	{
		printf("sh_section_offset: %u sh_section_size %u", node->sh_offset, node->sh_size);
		printf("guilty offset is: %u while file_size is: %lu\n", node->sh_offset + node->sh_size, nm->file_size);
		return (1);
	}
	if (node->sh_type == SHT_SYMTAB)
		return (parse_sh_link(nm, node->sh_link));
	return (0);
}

int	safety_32(t_nm *nm)
{
	uint64_t	dec;
	void		*cursor;
	Elf32_Shdr	*node;

	cursor = nm->map_begin + nm->section_header_offset;
	dec = nm->section_header_nb;
	while (dec)
	{
		node = (Elf32_Shdr *)cursor;
		if (parse_node_32(nm, node))
			return (1);
		cursor += nm->section_header_size;
		dec--;
	}
	return (0);
}

int	parse_node_64(t_nm *nm, Elf64_Shdr *node)
{
	if (add_overflow(node->sh_offset, node->sh_size,
		"Error: section header content + size cause overflow"))
		return (1);
	if (is_offset_out(nm, node->sh_offset + node->sh_size,
		"Error: section content is atleast partially out of bound"))
		return (1);
	if (node->sh_type == SHT_SYMTAB)
		return (parse_sh_link(nm, node->sh_link));
	return (0);
	
}

int	safety_64(t_nm *nm)
{
	uint64_t	dec;
	void		*cursor;
	Elf64_Shdr	*node;

	cursor = nm->map_begin + nm->section_header_offset;
	dec = nm->section_header_nb;
	while (dec)
	{
		node = (Elf64_Shdr *)cursor;
		if (parse_node_64(nm, node))
			return (1);
		cursor += nm->elf_header_size;
		dec--;
	}
	return (0);
}

int	safety_section_header_loop(t_nm *nm)
{
	if (nm->class == ELFCLASS64)
		return (safety_64(nm));
	else
		return (safety_32(nm));
}