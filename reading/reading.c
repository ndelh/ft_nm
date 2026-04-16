/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 11:30:50 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/13 17:40:26 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

void	retrieve_global_intel(t_nm *nm)
{
	Elf64_Ehdr	*cursor;

	cursor = (Elf64_Ehdr *)nm->map_begin;
	nm->endian = cursor->e_ident[EI_DATA];
	nm->osabi = cursor->e_ident[EI_OSABI];
	nm->version = cursor->e_ident[EI_VERSION];
}

void	fetch_32(t_nm *nm)
{
	Elf32_Ehdr	*cursor;

	cursor = (Elf32_Ehdr *)nm->map_begin;
	nm->section_offset = cursor->e_shoff;
	nm->entry_number = cursor->e_shnum;
	nm->table_name = cursor->e_shstrndx;
	nm->section_size = cursor->e_shentsize;
}


void	fetch_64(t_nm *nm)
{
	Elf64_Ehdr	*cursor;

	cursor = (Elf64_Ehdr *)nm->map_begin;
	nm->section_offset = cursor->e_shoff;
	nm->entry_number = cursor->e_shnum;
	nm->table_name = cursor->e_shstrndx;
	nm->section_size = cursor->e_shentsize;
}

void	fetch_data(t_nm *nm)
{
	if (nm->arch_type == 32)
		fetch_32(nm);
	else
		fetch_64(nm);
}

void	read_map(t_nm *nm)
{
	char	*s;
	void	*end;

	if (!is_elf(nm))
		return ;
	retrieve_global_intel(nm);
	ft_parse_global_intel(nm);
	fetch_data(nm);
	security_parse(nm);
	end = nm->map_end + 1;
	s = (char *)nm->map_begin;
	while (s != end)
	{
		write(1, s, 1);
		++s;
	}
	nm->section_begin = nm->map_begin + nm->section_offset;
	retrieve_namestring(nm);
}
