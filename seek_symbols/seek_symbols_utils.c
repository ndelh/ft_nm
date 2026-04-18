/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seek_symbols_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 18:13:24 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/18 18:16:14 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "seek_symbols.h"

/* Weak symbols can pop as w or v. v means variable. Uppercase means that
symbols is defined */

char	weak_case(uint16_t c, unsigned char st_info)
{
	if (ELF64_ST_TYPE(st_info) == STT_OBJECT)
	{
		if (c == SHN_UNDEF)
			return ('v');
		else
			return ('V');
	}
	if (c == SHN_UNDEF)
		return ('w');
	return ('W');
}

/* SHN_UNDEF means that the symbols isnt defined, often lead to external lib/func*/
/* SHN_ABS stands for absolute*/
/* SHN_COMMON represent a special index for unitiliazed global*/

char	special_case(uint16_t c, unsigned char st_info)
{
	if (ELF64_ST_BIND(st_info) == STB_WEAK)
		return (weak_case(c, st_info));
	else if (c == SHN_UNDEF)
		return ('U');
	else if (c == SHN_ABS)
		return ('A');
	else if (c == SHN_COMMON)
		return ('C');
	return (0);
}

char	retrieve_current_flags(uint64_t flags, uint32_t type)
{
	if (type == SHT_NOBITS)
		return ('B');
	if (flags & SHF_EXECINSTR)
		return ('T');
	if (flags & SHF_WRITE)
		return ('D');
	if (flags & SHF_ALLOC)
        return ('R');
	return ('N');
}
