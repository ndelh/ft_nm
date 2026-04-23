/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_symbols_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:04:07 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/23 18:10:36 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "retrieve_symbols.h"

void	fetch_sym_name_32(t_current_nm *nm, Elf32_Shdr *symtab_name)
{
	nm->str_sym_name_offset = symtab_name->sh_offset;
	nm->str_sym_name_size = symtab_name->sh_size;
}

void	fetch_sym_name_64(t_current_nm *nm, Elf64_Shdr *symtab_name)
{
	nm->str_sym_name_offset = symtab_name->sh_offset;
	nm->str_sym_name_size = symtab_name->sh_size;
}

void	parse_retrieve_symtab_content(t_data *data, t_current_nm *nm)
{
	if (range_check(data, nm->str_sym_name_offset, 1, nm->str_sym_name_size,
		"invalid linked strtab content"))
			return ;
	nm->sym_name = nm->map_begin + nm->str_sym_name_offset;
	if (nm->sym_name[0] != 0 || nm->sym_name[nm->str_sym_name_size - 1] != 0)
		return (nm_error(data, "non enclosed strtable content for symbole name"));
}

void	retrieve_symbols_name(t_data *data, t_current_nm *nm)
{
	void	*cursor;

	if (data->dead_nm)
		return ;
	cursor = nm->map_begin + (nm->sym_name_index * nm->section_header_size)
		+ nm->section_header_offset;
	if (((Elf64_Shdr *)cursor)->sh_type != SHT_STRTAB)
		return (nm_error(data, "invalid type for symtab linked header"));
	if (nm->class == ELFCLASS32)
		fetch_sym_name_32(nm, (Elf32_Shdr *)cursor);
	else
		fetch_sym_name_64(nm, (Elf64_Shdr *)cursor);
	parse_retrieve_symtab_content(data, nm);
}
