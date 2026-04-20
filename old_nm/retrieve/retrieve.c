/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:18:56 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/16 18:04:47 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "retrieve.h"

int	check_data(t_nm *nm)
{	
	if (!nm->section_header_offset)
		return (0);
	if (nm->section_header_string_table_index >= nm->section_header_nb)
	{
		ft_putendl_fd("Error: out of bounds shstr", 2);
		return (1);
	}
	if (nm->elf_header_size > nm->section_header_offset)
	{
		ft_putendl_fd("Error: section header offset leads inside ELF header", 2);
		return (1);
	}
	if (add_range_overflow(nm->section_header_offset,
		nm->section_header_size, nm->section_header_nb,
		" dubious section header or offset size"))
		return (1);
	if (is_section_out(nm, nm->section_header_offset,
		nm->section_header_size, nm->section_header_nb,
		" section header is atleast partially out of bound"))
		return (1);
	return (0);
}

int	retrieve(t_nm *nm)
{
	if (!nm->map_begin)
		return (1);
	if (retrieve_16_bytes(nm))
		return (1);
	if (fetch(nm))
		return (1);
	if (check_data(nm))
		return (1);
	if (retrieve_shstr_content(nm))
		return (1);
	return (0);
}
