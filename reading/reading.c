/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 11:30:50 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/13 14:00:46 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

void	read_map(t_nm *nm)
{
	char	*s;
	void	*end;

	if (!ft_parse(nm))
		return ;
	end = nm->map_end + 1;
	s = (char *)nm->map_begin;
	while (s != end)
	{
		write(1, s, 1);
		++s;
	}
}
