/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:43:04 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/14 09:23:10 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

void print_name(t_nm *nm)
{
	uint64_t	i;
	char		*s;

	if (!is_valid_namestring(nm))
		return ;
	s = nm->header_name;
	i = nm->header_name_size;
	while (i)
	{
		if (*s == 0)
			write(1, "\n", 1);
		else
			write(1, s, 1);
		s++;
		--i;
	}
}

int	retrieve_64(t_nm *nm, void *cursor)
{
	Elf64_Shdr*	fetch;

	fetch = (Elf64_Shdr *)cursor;
	if (!is_inbound(nm, fetch->sh_offset))
		return (parse_error("out of bound data for table name"));
	nm->header_name = (char *)nm->map_begin + fetch->sh_offset;
	printf("sh offset of tablename :%zu\n", fetch->sh_offset);
	nm->header_name_size = fetch->sh_size;
	printf("sh_size of stringtable name:%zu\n", fetch->sh_size);
	//printf("%zu\n", fetch->sh_size);
	if (check_addition_overflow(fetch->sh_offset, fetch->sh_size))
		return (parse_error("impossible size for table name data"));
	if (!is_inbound(nm, (fetch->sh_offset + fetch->sh_size)))
		return (parse_error("out of bound content for data_table name"));
    return (1);
}

int	retrieve_32(t_nm *nm, void *cursor)
{
	Elf32_Shdr*	fetch;

	fetch = (Elf32_Shdr *)cursor;
	if (!is_inbound(nm, fetch->sh_offset))
		return (parse_error("out of bound data for table name"));
	nm->header_name = (char *)nm->map_begin + fetch->sh_offset;
	printf("sh offset of tablename :%u\n", fetch->sh_offset);
	nm->header_name_size = fetch->sh_size;
	printf("sh_size of stringtable name:%u\n", fetch->sh_size);
	//printf("%zu\n", fetch->sh_size);
	if (check_addition_overflow(fetch->sh_offset, fetch->sh_size))
		return (parse_error("impossible size for table name data"));
	if (!is_inbound(nm, (fetch->sh_offset + fetch->sh_size)))
		return (parse_error("out of bound content for data_table name"));
    return (1);
}

void	retrieve_namestring(t_nm *nm)
{
	void	*cursor;
	int		flag;

	printf("table name index: %zu\n", nm->table_name);
	printf("section size: %lu\n", nm->section_size);
	cursor = nm->section_begin + (nm->table_name * nm->section_size);
	printf("begin map: %p\n", nm->map_begin);
	printf("cursor: %p\n", cursor);
	if (nm->arch_type == 64)
		flag = retrieve_64(nm, cursor);
	else
		flag = retrieve_32(nm, cursor);
	if (!flag)
		return ;
	//print_name(nm);
}
