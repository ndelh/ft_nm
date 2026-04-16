/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 16:27:35 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/16 17:09:15 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "retrieve.h"

int	retrieve_variable_intel_32(t_nm *nm, Elf32_Ehdr *header)
{
	if (header->e_ehsize != 52)
	{
		ft_putendl_fd("Error: corrupted Elf header size", 2);
		return (1);
	}
	if (header->e_shentsize != 52)
	{
		ft_putendl_fd("corrupted programm header size", 2);
		return (1);
	}
	nm->section_header_offset = header->e_shoff;
	nm->section_header_nb = header->e_shnum;
	nm->section_header_size = header->e_shentsize;
	nm->section_header_string_table_index = header->e_shstrndx;
	nm->elf_header_size = header->e_ehsize;
	return (0);
}

int	fetch_32(t_nm *nm)
{
	Elf32_Ehdr *header;

	header = (Elf32_Ehdr *)nm->map_begin;
	if (retrieve_variable_intel_32(nm, header))
		return (1);
	return (0);
}

int	retrieve_variable_intel_64(t_nm *nm, Elf64_Ehdr *header)
{
	if (header->e_ehsize != 64)
	{
		ft_putendl_fd("Error: corrupted Elf header size", 2);
		return (1);
	}
	if (header->e_shentsize != 64)
	{
		ft_putendl_fd("corrupted programm header size", 2);
		return (1);
	}
	nm->section_header_offset = header->e_shoff;
	nm->section_header_nb = header->e_shnum;
	nm->section_header_size = header->e_shentsize;
	nm->section_header_string_table_index = header->e_shstrndx;
	nm->elf_header_size = header->e_ehsize;
	return (0);
}

int	fetch_64(t_nm *nm)
{
	Elf64_Ehdr *header;

	if (nm->file_size < 64)
	{
		ft_putendl_fd("Error: file too short for 64 bytes architecture", 2);
		return (1);
	}
	header = (Elf64_Ehdr *)nm->map_begin;
	if (retrieve_variable_intel_64(nm, header))
		return (1);
	return (0);
}

int	fetch(t_nm *nm)
{
	if (nm->class == ELFCLASS64)
		return (fetch_64(nm));
	else
		return (fetch_32(nm));
}
