/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:15:01 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/20 20:20:00 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "end_nm.h"

void	free_all(t_current_nm *nm)
{
	free(nm->stat);
	free(nm);
}

void	close_all(t_current_nm *nm)
{
	if (nm->fd != -1)
		close(nm->fd);
	if (nm->map_begin != MAP_FAILED)
		munmap(nm->map_begin, nm->file_size);
}


void	clean_current_nm(t_current_nm *nm)
{
	close_all(nm);
	free_all(nm);
}

void	end_nm(t_data *data, t_current_nm *current_nm)
{
	data->dead_nm = 0;
	if (current_nm)
	{
		clean_current_nm(current_nm);
		data->current_nm = NULL;
	}
}
