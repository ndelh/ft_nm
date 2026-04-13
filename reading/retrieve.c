/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:43:04 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/13 19:42:19 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

int	retrieve_64(t_nm *nm, void *cursor)
{
	Elf64_Shdr*	fetch;

	fetch = (Elf64_Shdr *)cursor;
	nm->string_name = (char *)nm->map_begin + fetch->sh_offset;
	//need to check overflow
	nm->string_name_size = fetch->sh_size;
	//need to check inbound of offset + size and  overflow
    return (1);
}

int	retrieve_32(t_nm *nm, void *cursor)
{
	Elf32_Shdr*	fetch;

	fetch = (Elf32_Shdr *)cursor;
	nm->string_name = (char *)nm->map_begin + fetch->sh_offset;
	//need to check overflow
	nm->string_name_size = fetch->sh_size;
	//need to check inbound of offset + size and  overflow
    return (1);
}

void	retrieve_label(t_nm *nm)
{
	unsigned char	*cursor;
	int		flag;

	cursor = (unsigned char *)nm->map_begin + nm->table_name;
	//need to check overflow and tablename inbound here
	if (nm->arch_type = 64)
		flag = retrieve_64(nm, cursor);
	else
		flag = retrieve_64(nm, cursor);
}
