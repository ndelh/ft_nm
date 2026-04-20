/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_symtab_intel_64_utils.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:18:15 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/20 14:27:26 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "seek_symbols.h"

char	*retrieve_name_value_64(uint64_t type, Elf64_Sym *current,
		char *strtab, t_nm *nm)
{
	uint64_t index;
	char	*to_ret;
	
	(void)nm;
	index = current->st_name;
	if (type == STT_SECTION && index == 0)
		return (0);
	to_ret = ft_strdup(strtab + index);
	return (to_ret);
}
