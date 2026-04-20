/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_section_header_string_table.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:25:24 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/16 18:34:42 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "retrieve.h"

void	retrieve_string_table_64(t_nm *nm, void *shstr)
{
	Elf64_Shdr	*node;

	node = (Elf64_Shdr *)shstr;
	nm->shstr_content_offset = node->sh_offset;
	nm->shstr_content_size = node->sh_size;
}

void	retrieve_string_table_32(t_nm *nm, void *shstr)
{
	Elf32_Shdr	*node;

	node = (Elf32_Shdr *)shstr;
	nm->shstr_content_offset = node->sh_offset;
	nm->shstr_content_size = node->sh_size;
}

int	parse_shstr_content(t_nm *nm)
{
	if (is_offset_out(nm, nm->shstr_content_offset, "Error: out of bound shstr offset"))
		return (1);
	if (add_overflow(nm->shstr_content_offset, nm->shstr_content_size, "Error: dubious shstr content"))
		return (1);
	if (is_offset_out(nm, nm->shstr_content_offset + nm->shstr_content_size, "Error: shstr section is out of bounds"))
		return (1);
	return (0);
}

void	print_name(t_nm *nm)
{
	char	*s;
	size_t	dec;

	s = (char *)nm->map_begin + nm->shstr_content_offset;
	dec = nm->shstr_content_size;
	while (dec)
	{
		if (!*s)
			write(1, "\n", 1);
		else
			write(1, s, 1);
		++s;
		--dec;
	}

}

int	retrieve_shstr_content(t_nm *nm)
{
	void	*shstr;

	if (!nm->section_header_string_table_index)
		return (0);
	shstr = nm->map_begin + nm->section_header_offset +
		(nm->section_header_string_table_index * nm->section_header_size);
	if (nm->class == ELFCLASS64)
		retrieve_string_table_64(nm, shstr);
	else
		retrieve_string_table_32(nm, shstr);
	if (parse_shstr_content(nm))
		return (1);
	//print_name(nm);
	return (0);
}
