/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_shstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:32:27 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/22 11:46:04 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_init.h"

void	parse_retrieve_shstr_intels(t_data *data, t_current_nm *nm)
{
	char	*content;

	if (data->dead_nm)
		return ;
	if (range_check(data, nm->shstr_content_offset, 1, nm->shstr_content_size,
		"corrupted content range for shstr table"))
			return ;
	content = (char *)nm->map_begin + nm->shstr_content_offset;
	if (content[0] || content[nm->shstr_content_size])
	{
		nm_error(data, "corrupted shstr table content, must be enclosed by '\0'");
		return ;
	}
	//print_table_name(content, nm->shstr_content_size);
	nm->header_name = content;
}

void	retrieve_shstr_32(t_data *data,t_current_nm *nm, Elf32_Shdr *shstr_table)
{
	if (shstr_table->sh_type != SHT_STRTAB)
		return (nm_error(data, "invalid shstr tab type"));
	nm->shstr_content_offset = shstr_table->sh_offset;
	nm->shstr_content_size = shstr_table->sh_size;
}

void	retrieve_shstr_64(t_data *data, t_current_nm *nm, Elf64_Shdr *shstr_table)
{
	if (shstr_table->sh_type != SHT_STRTAB)
		return (nm_error(data, "invalid shstr tab type"));
	nm->shstr_content_offset = shstr_table->sh_offset;
	nm->shstr_content_size = shstr_table->sh_size;
}

void	fetch_shstr_intels(t_data *data, t_current_nm *nm)
{
	void	*shstr_table_begin;

	if (data->dead_nm)
		return ;
	shstr_table_begin = nm->map_begin + nm->section_header_offset
		+ (nm->section_header_size * nm->shstr_index);
	if (nm->class == ELFCLASS32)
		retrieve_shstr_32(data, nm, (Elf32_Shdr *)shstr_table_begin);
	else
		retrieve_shstr_64(data, nm, (Elf64_Shdr *)shstr_table_begin);
	parse_retrieve_shstr_intels(data, nm);
}
