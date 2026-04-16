/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:05:11 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/16 14:42:52 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	add_overflow(uint64_t a, uint64_t b, char *s)
{
	if (b <= 0xFFFFFFFFFFFFFFFF - a)
		return (0);
	if (s)
		ft_putendl_fd(s, 2);
	return (1);
}


int	mul_overflow(uint64_t a, uint64_t b, char *s)
{
	if (a == 0 || b == 0)
		return (0);
	if (a <= (0xffffffffffffffff / b))
		return (0);
	if (s)
		ft_putendl_fd(s, 2);
	return (1);
}

int	add_range_overflow(uint64_t offset, uint64_t struct_size, uint64_t struct_nb, char *s)
{
	uint64_t	total_size;

	if (mul_overflow(struct_size, struct_nb, NULL))
	{
		write(2, "error: impossible struct size", 30);
		if (s)
			ft_putendl_fd(s, 2);
		return (1);
	}
	total_size = struct_size * struct_nb;
	if (add_overflow(offset, total_size, NULL))
	{
		write(2, "error: impossible addition between offset and total section size", 65);
		if (s)
			ft_putendl_fd(s, 2);
		return (1);
	}
	return (0);
}

