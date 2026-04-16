/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_symtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:32:51 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/16 12:40:08 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symbols.h"

void	retrieve_strtab_64(t_nm *nm)
{
	Elf64_Shdr	*cursor;
	size_t		size;
	
	size = nm->entry_number;
	cursor = (Elf64_Shdr *)nm->section_begin;
	while (size && cursor->sh_type != SHT_STRTAB)
	{
		++cursor;
		--size;
	}
	if (size)
	{
		//parseoverflow and oob
		nm->string_tab_size = cursor->sh_size;
		nm->string_tab = (char *)nm->map_begin + cursor->sh_offset;
	}
}

void	retrieve_strtab(t_nm *nm)
{
	if (nm->arch_type == 64)
		retrieve_strtab_64(nm);
}
