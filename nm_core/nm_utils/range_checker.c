/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:20:21 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/21 19:38:58 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_utils.h"

int	offset_check(t_data *data, t_current_nm *nm, uint64_t offset, char *s)
{
	if (offset > nm->file_size)
	{
		nm_error(data, s);
		return (1);
	}
	return (0);
}

int	range_check(t_data *data, uint64_t offset, uint64_t struct_size,
		uint64_t struct_nb, char *s)
{
	uint64_t	total_size;

	mul_overflow(struct_size, struct_nb, s, data);
	if (data->dead_nm)
		return (1);
	total_size = struct_size * struct_nb;
	add_overflow(offset, total_size, s, data);
	if (data->dead_nm)
		return (1);
	if (offset_check(data, data->current_nm, offset + total_size, s))
		return (1);
	return (0);
}
