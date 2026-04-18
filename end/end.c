/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:44:50 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/11 17:00:34 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_nm.h"

void	close_fd(t_nm *nm)
{
	if (nm->fd != -1)
		close(nm->fd);
}

void	close_map(t_nm *nm)
{
	if (nm->map_begin && nm->map_begin != MAP_FAILED)
		munmap(nm->map_begin, (size_t)nm->file_size);
}

void	free_list(t_symbol *list)
{
	t_symbol *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->name);
		free(tmp);
	}
}

void	ft_end(t_nm *nm)
{
	if (!nm)
		return ;
	close_fd(nm);
	close_map(nm);
	if (nm->stat)
		free(nm->stat);
	if (nm->print_list)
		free_list(nm->print_list);
	free(nm);
}
