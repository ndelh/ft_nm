/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_symtab_intels.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:18:12 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/23 12:20:21 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "retrieve_symbols.h"

void    fetch_symtab_intels_32(t_current_nm *nm, Elf32_Shdr *cursor)
{
    nm->symtab_content_offset = cursor->sh_offset;
    nm->symtab_content_size = cursor->sh_size;
    nm->symstruct_size = cursor->sh_entsize;
    nm->sym_name_index = cursor->sh_link;
}

void    fetch_symtab_intels_64(t_current_nm *nm, Elf64_Shdr *cursor)
{
    nm->symtab_content_offset = cursor->sh_offset;
    nm->symtab_content_size = cursor->sh_size;
    nm->symstruct_size = cursor->sh_entsize;
    nm->sym_name_index = cursor->sh_link;
}

void    parse_symtab_intels(t_data *data, t_current_nm *nm)
{
    if (nm->sym_name_index >= nm->section_header_nb)
        return (nm_error(data, "invalid sh_link in atleast one table"));
    if (range_check(data, nm->symtab_content_offset, nm->symtab_content_size, 1,
        "corrupted sh_content for atleast one table"))
        return ;
}

void	retrieve_symtab_intels(t_data *data, t_current_nm *nm, void *cursor)
{
	if (nm->class == ELFCLASS32)
		fetch_symtab_intels_32(nm, (Elf32_Shdr *)cursor);
	else
		fetch_symtab_intels_64(nm, (Elf64_Shdr *)cursor);
	parse_symtab_intels(data, nm);
    retrieve_symbols_name(data, nm);
}
