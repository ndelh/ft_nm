/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:16:40 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/19 14:33:35 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	open_file(t_nm *nm, char *s)
{
	nm->fd = open(s, O_RDONLY);
	if (nm->fd == -1)
	{
		perror(s);
		return ;
	}
}

void	fetch_stat(t_nm *nm)
{
	if (nm->fd == -1)
		return ;
	nm->page_size = getpagesize();
q	if (!nm->stat)
		return ;
	nm->fstat_result = fstat(nm->fd, nm->stat);
}

void	memory_init(t_nm *nm)
{
	if (nm->fstat_result == -1)
		return ;
	nm->file_size = (uint64_t)nm->stat->st_size;
	if (nm->file_size < 52)
	{
		print_simple_error("ELF binary file size cannot be less than 52 for Elf 32");
		return ;
	}
	nm->map_begin = mmap(NULL, (size_t)nm->file_size, PROT_READ, MAP_PRIVATE, nm->fd, 0);
	if (nm->map_begin == MAP_FAILED)
		print_error("nmap failed to allocate due to:");
	nm->map_end = nm->map_begin + nm->file_size;
}

t_nm	*init(char **argv)
{
	t_nm	*to_ret;

	to_ret = malloc(sizeof(struct s_nm));
	if (!to_ret)
		return (to_ret);
	ft_memset(to_ret, 0, sizeof(struct s_nm));
	retrieve_flag_and_files(to_ret, argv);
	return (to_ret);
}
