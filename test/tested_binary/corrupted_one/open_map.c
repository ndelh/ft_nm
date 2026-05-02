/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:59:55 by ndelhota          #+#    #+#             */
/*   Updated: 2026/05/02 18:22:16 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corruptor.h"

void	fetch_stat(t_corrupt *data)
{
	data->stat = malloc(sizeof(struct stat));
	if (!data->stat)
		ft_end(data, 1, "lstat malloc call");
	if ((fstat(data->fd, data->stat) == -1))
		ft_end(data, 1, "lstat call");
	data->file_size = data->stat->st_size;
}

void	open_nmap(t_corrupt *data)
{
	data->file_begin = mmap(NULL, data->file_size, PROT_READ | PROT_WRITE, MAP_SHARED, data->fd, 0);
	if (data->file_begin == MAP_FAILED)
		ft_end(data, 1, "mmap call");
}

void	open_map(t_corrupt *data)
{
	fetch_stat(data);
	open_nmap(data);
}
