/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seek_symbols.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:33:31 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/16 19:35:00 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "seek_symbols.h"

void	retrieve_symtab_intel(t_nm *nm)
{
	if (nm->class == ELFCLASS64)
		retrieve_symtab_intel_64(nm);
}

void	seek_symbols(t_nm *nm)
{
	safety_section_header_loop(nm);
	retrieve_symtab_intel(nm);
}



