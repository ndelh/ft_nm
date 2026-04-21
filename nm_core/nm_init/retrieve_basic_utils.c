/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_basic_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:55:15 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/21 17:56:49 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_init.h"

void	parse_first_char_intel(t_data *data, t_current_nm *nm)
{
	if (nm->class != ELFCLASS32 && nm->class != ELFCLASS64)
		return (nm_error(data, "invalid Elf class must be 32 or 64"));
	if (nm->endian != ELFDATA2LSB && nm->endian != ELFDATA2MSB)
		return (nm_error(data, "invalid ELF endian type"));
	if (nm->version != 1)
		return (nm_error(data, "invalid version or executable is from future"));
}

void	offset_calculus(t_data *data, t_current_nm *nm)
{
	if (data->dead_nm)
		return ;
	(void)nm;
}


void	shdr_size_and_index(t_data *data, t_current_nm *nm)
{
	if (!nm->section_header_offset && nm->section_header_nb)
		return (nm_error(data, "eshoff point on beginning of EHDR, not possible"));
	if (nm->class == ELFCLASS32 && nm->section_header_size != 40)
		return (nm_error(data, "corrupted section header size for elf 32"));
	if (nm->class == ELFCLASS64 && nm->section_header_size != 64)
		return (nm_error(data, "corrupted section header size for elf 64"));
	if (nm->shstr_index > nm->section_header_nb)
		return (nm_error(data, "out of bound shstr table index"));
	if (!nm->shstr_index && nm->section_header_nb)
		return (nm_error(data, "corrupted shstr index, can't be 0"));
}

void	parse_shdr_intels(t_data *data, t_current_nm *nm)
{
	if (data->dead_nm)
		return ;
	shdr_size_and_index(data, nm);
	offset_calculus(data, nm);
}