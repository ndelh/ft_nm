/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 12:41:13 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/13 13:18:27 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

int	is_32(t_nm *nm)
{
	(void)nm;
	return (0);
}

int	is_64(t_nm *nm)
{
	(void)nm;
	if (nm->stat->st_size < 64)
	{
		print_simple_error("Elf 64 binary cannot be less than 64 bytes");
		return (0);
	}
	return (1);
}

int	ft_parse(t_nm *nm)
{
	if (is_32(nm))
		return (1);
	return (is_64(nm));
}
