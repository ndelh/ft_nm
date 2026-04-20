/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sh_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 13:03:07 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/17 13:04:22 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "seek_symbols.h"

//need to add non zero shentsize check

int	is_string_valid(char *s, uint64_t size)
{
	if (s[size] != 0 || *s)
		return (1);
	return (0);
}

int	parse_sh_link_32(t_nm *nm, Elf32_Shdr *linked_header)
{
	if (linked_header->sh_type != SHT_STRTAB)
	{
		print_simple_error("Symtab link point to a non STR_TAB header");
		return (1);
	}
	if (add_overflow(linked_header->sh_offset, linked_header->sh_size,
		"Symtab section calculs leads to an overflow, corrupted size"))
		return (1);
	if (is_offset_out(nm, linked_header->sh_offset + linked_header->sh_size,
		"atleast a part of linked strtab to symtab is out of bounds"))
		return (1);
	return (0);
}

int	parse_sh_link_64(t_nm *nm, Elf64_Shdr *linked_header)
{
	if (linked_header->sh_type != SHT_STRTAB)
	{
		print_simple_error("Symtab link point to a non STR_TAB header");
		return (1);
	}
	if (add_overflow(linked_header->sh_offset, linked_header->sh_size,
		"Symtab section calculs leads to an overflow, corrupted size"))
		return (1);
	if (is_offset_out(nm, linked_header->sh_offset + linked_header->sh_size,
		"atleast a part of linked strtab to symtab is out of bounds"))
		return (1);
	return (0);
}

int	parse_sh_link(t_nm *nm, uint64_t index)
{
	void	*linked_header;
	
	if (index >= nm->section_header_nb)
	{
		print_simple_error("Atleast a symtab link leads to an out of bounds");
		return (1);
	}
	linked_header = nm->map_begin + nm->section_header_offset + (nm->section_header_size * index);
	if (nm->class == ELFCLASS64)
		return (parse_sh_link_64(nm, (Elf64_Shdr *)linked_header));
	else 
		return (parse_sh_link_32(nm, (Elf32_Shdr *)linked_header));
}
