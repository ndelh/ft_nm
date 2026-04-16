/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbols.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:19:27 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/14 13:59:41 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symbols.h"

void	print_sym_intel(t_nm* nm, Elf64_Sym *cursor)
{
	//ofc we need to parse all in final version
	printf("symbol name is:\n ");
	ft_putendl_fd(nm->string_tab + cursor->st_name ,1);
}

void	display_symtab(Elf64_Shdr *node, t_nm *nm)
{
	size_t		offset;
	size_t		flags;
	size_t		size;
	Elf64_Sym	*cursor;
	char		*begin_symtab;

	offset = node->sh_offset;
	flags = node->sh_flags;
	size = node->sh_size;
	begin_symtab = (char *)nm->map_begin + offset;
	cursor = (Elf64_Sym *)begin_symtab;
	while (size)
	{
		print_sym_intel(nm, cursor);
		++cursor;
		--size;
	}

}

void	print_header_intel(Elf64_Shdr *node, t_nm *nm)
{
	size_t	offset;
	
	offset = node->sh_name;
	if (offset > nm->header_name_size)
	{
		print_error("name value out of bound");
		return;
	}
	ft_putendl_fd(nm->header_name + offset, 1);
	if (node->sh_type == SHT_SYMTAB)
		display_symtab(node, nm);
}

void	treat_64(t_nm *nm)
{
	void		*cursor;
	uint64_t	dec;
	Elf64_Shdr*	node;

	cursor = nm->section_begin;
	dec = nm->entry_number;
	while (dec)
	{
		//need to add a parse condition node size cannot diverge from secction_size
		node = (Elf64_Shdr *)cursor;
		print_header_intel(node, nm);
		--dec;
		cursor += nm->section_size;
	}
}

void	symbols(t_nm *nm)
{
	retrieve_strtab(nm);
	if (nm->section_size == 64)
		treat_64(nm);
}
