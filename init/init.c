/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:16:40 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/11 17:27:29 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_nm.h"

void	open_file(t_nm *nm, char *s)
{
	nm->fd = open(s, O_RDONLY);
}

void	fetch_stat(t_nm *nm)
{
	if (nm->fd == -1)
		return ;
	nm->page_size = getpagesize();
	nm->stat = malloc(sizeof(struct stat));
	if (!nm->stat)
		return ;
	nm->fstat_result = fstat(nm->fd, nm->stat);
}

void	memory_init(t_nm *nm)
{
	if (nm->fstat_result == -1)
		return ;
	nm->map_begin = mmap(NULL, (size_t)nm->stat->st_size, PROT_READ, MAP_PRIVATE, nm->fd, 0);
	if (nm->map_begin == MAP_FAILED)
		print_error("nmap failed to allocate due to :");
	nm->map_end = nm->map_begin + nm->stat->st_size;
}

t_nm	*init(char *s)
{
	t_nm	*to_ret;

	to_ret = malloc(sizeof(struct s_nm));
	if (!to_ret)
		return (to_ret);
	ft_memset(to_ret, 0, sizeof(struct s_nm));
	open_file(to_ret, s);
	fetch_stat(to_ret);
	memory_init(to_ret);
	return (to_ret);
}
