/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:54:30 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/20 19:58:11 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_init.h"

void	fetch_stat(t_data *data, t_current_nm *nm)
{
		if (data->dead_nm)
			return ;
		nm->stat = malloc(sizeof(struct stat));
		if (!nm->stat)
			return (nm_error(data, "stat struct allocation failed"));
		if (fstat(nm->fd, nm->stat) == -1)
			return (nm_error(data, "fstat_failed"));
		nm->file_size = nm->stat->st_size;
}

void	mapping_file(t_data *data, t_current_nm *nm)
{
		if (data->dead_nm)
			return ;
		if (nm->file_size < 8)
			return (nm_error(data, "file shorter than an unsigned char"));
		nm->map_begin = mmap(NULL, nm->file_size, PROT_READ, MAP_PRIVATE, nm->fd, 0);
		if (nm->map_begin == MAP_FAILED)
			return (nm_error(data, NULL));
}

void	open_nm(t_data *data, t_current_nm *current_nm)
{
	if (data->dead_nm)
		return ;
	current_nm->fd = open(data->current_file, O_RDONLY);
	if (current_nm->fd == -1)
		nm_error(data, NULL);
}

void	create_nm(t_data *data)
{
	data->current_nm = malloc(sizeof(t_current_nm));
	if (!data->current_nm)
		nm_error(data, "malloc of nm struct failed");
	ft_memset(data->current_nm, 0, sizeof(t_current_nm));
	data->current_nm->map_begin = MAP_FAILED;
}

void	init_nm(t_data *data)
{
	create_nm(data);
	open_nm(data, data->current_nm);
	fetch_stat(data, data->current_nm);
	mapping_file(data, data->current_nm);
}
