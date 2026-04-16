/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 12:41:13 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/14 08:25:06 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

int	ft_parse_global_intel(t_nm *nm)
{
	if (nm->version != 1)
	{
		print_simple_error("binary error present invalid or future version");
		nm->arch_type = 0;
		return (0);
	}
	return (1);
}

int	is_elf(t_nm *nm)
{
	Elf64_Ehdr	*cursor;

	cursor = (Elf64_Ehdr *)nm->map_begin;
	if (ft_memcmp(cursor, ELFMAG, SELFMAG) != 0)
	{
		print_simple_error("binary show invalid or non Elf header");
		return (0);
	}
	nm->arch_type = (int)cursor->e_ident[4];
	if (nm->arch_type == 2 && (nm->map_end - nm->map_begin < 64))
	{
		print_simple_error("Binary presented is too short for an ELF64 file");
		nm->arch_type = 0;
		return (0);
	}
	if (nm->arch_type == 1)
		nm->arch_type = 32;
	else if (nm->arch_type == 2)
		nm->arch_type = 64;
	else
	{
		nm->arch_type = 0;
		print_simple_error("invalid Elf file format, must be 32 or 64 bits");
	}
	return (1);
}

int	security_parse(t_nm *nm)
{
	uint64_t	tester;
	uint64_t	store;

	if ((nm->arch_type == 64 && nm->section_size != 64)
		|| (nm->arch_type == 32 && nm->section_size != 52))
		return (parse_error("missmatch between arch type and section header size"));
	if (nm->entry_number && nm->section_size > 0xffffffffffffffff / nm->entry_number)
		return (parse_error("overflow detected"));
	tester =  nm->section_offset;
	if (tester > (uint64_t)nm->file_size)
		return (parse_error("section offset lead to out of bound"));
	store = tester;
	tester += nm->section_size * nm->entry_number;
	if (tester < store)
		return (parse_error("overflow detected"));
	if (tester > (uint64_t)nm->file_size)
		return (parse_error("atleat a part of section header is out of bound"));
	if (nm->table_name >= nm->entry_number)
		return (parse_error("out of bound tablename"));
	return 1;
}
