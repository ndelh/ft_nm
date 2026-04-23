/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_basics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:11:21 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/21 17:33:51 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_init.h"

void	fetch_header_64(t_data *data, t_current_nm *nm)
{
	Elf64_Ehdr	*head;

	if (nm->file_size < 64)
		return (nm_error(data, "file too short for ELK 64 header"));
	head = (Elf64_Ehdr *)nm->map_begin;
	nm->section_header_offset = head->e_shoff;
	nm->section_header_nb = head->e_shnum;
	nm->section_header_size = head->e_shentsize;
	nm->shstr_index = head->e_shstrndx;
}

void	fetch_header_32(t_data *data, t_current_nm *nm)
{
	Elf32_Ehdr	*head;

	if (nm->file_size < 52)
		return (nm_error(data, "file too short for ELK 64 header"));
	head = (Elf32_Ehdr *)nm->map_begin;
	nm->section_header_offset = head->e_shoff;
	nm->section_header_nb = head->e_shnum;
	nm->section_header_size = head->e_shentsize;
	nm->shstr_index = head->e_shstrndx;
}

void	fetch_header_intels(t_data *data, t_current_nm *nm)
{
	if (data->dead_nm)
		return ;
	if (nm->class == ELFCLASS64)
		fetch_header_64(data, nm);
	else
		fetch_header_32(data, nm);
	parse_shdr_intels(data, nm);
}

void	fetch_first_char_intels(t_data *data, t_current_nm *nm)
{
	unsigned char *ident;

	ident = (unsigned char *)nm->map_begin;

	if (ft_strncmp((char *)ident, ELFMAG, SELFMAG))
		return (nm_error(data, "this file is not an elf_file"));
	nm->class = ident[EI_CLASS];
	nm->endian = ident[EI_DATA];
	nm->version = ident[EI_VERSION];
	nm->osabi = ident[EI_OSABI];
	parse_first_char_intel(data, nm);
}

void	retrieve_basic(t_data *data, t_current_nm *nm)
{
	if (data->dead_nm)
		return ;
	fetch_first_char_intels(data, nm);
	fetch_header_intels(data, nm);
	fetch_shstr_intels(data, nm);
}
