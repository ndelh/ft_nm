/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_of_bound_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:48:05 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/16 14:57:01 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/* proceed to this functions only after overflow check*/

int	is_offset_out(t_nm *nm, uint64_t offset, char *s)
{
	if (offset > nm->file_size)
	{
		if (s)
			ft_putendl_fd(s, 2);
		return (1);
	}
	return (0);
}

int	is_section_out(t_nm *nm, uint64_t offset, uint64_t struct_size, uint64_t struct_nb, char *s)
{
	uint64_t	section_end;

	section_end = offset + (struct_size * struct_nb);
	if (section_end > nm->file_size)
	{
		if (s)
			ft_putendl_fd(s, 2);
		return 1;		
	}
	return (0);
}

