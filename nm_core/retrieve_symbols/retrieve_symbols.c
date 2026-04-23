/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_symbols.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:57:52 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/23 12:01:46 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "retrieve_symbols.h"

void	retrieve_symbols(t_data *data, t_current_nm *nm)
{
	void	*cursor;
	size_t	iteration;
	
	if (data->dead_nm)
		return ;
	cursor = nm->map_begin + nm->section_header_offset;
	if (((Elf64_Shdr *)cursor)->sh_type != SHT_NULL)
		return (nm_error(data, "invalid first section header type"));
	iteration = nm->section_header_nb;
	while (iteration)
	{
		if (((Elf64_Shdr *)cursor)->sh_type == SHT_SYMTAB)
		{
			retrieve_symtab_intels(data, nm, cursor);
		}
		cursor += nm->section_header_size;
		--iteration;
	}
}
