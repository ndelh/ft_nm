/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 12:41:13 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/13 14:00:22 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

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
	return (1);
}

int	ft_parse(t_nm *nm)
{
	if (!is_elf(nm))
		return (0);
	return (1);
}
