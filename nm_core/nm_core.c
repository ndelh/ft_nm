/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:45:17 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/20 19:48:16 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_core.h"

void	nm_loop(t_data *data)
{
	char **file;

	file = data->file_to_nm;
	while (*file)
	{
		data->current_file = *file;
		init_nm(data);
		// fetch_nm(data);
		end_nm(data, data->current_nm);
		++file;
	}
}
