/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 08:10:04 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/14 09:31:48 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

int	parse_error(char *s)
{
	print_simple_error(s);
	return (0);
}

int	is_valid_namestring(t_nm *nm)
{
	if (!nm->string_name_size)
		return (parse_error("0 string name size"));
	if (nm->string_name[0] != 0)
		return (parse_error("invalid first char for tabstring"));
	if (nm->string_name[nm->string_name_size - 1] != 0)
		return (parse_error("non null terminated stringname"));
	return (1);
}

int	check_multiply_overflow(uint64_t a, uint64_t b)
{
	if (a == 0 || b == 0)
		return (0);
	if (a < (0xffffffffffffffff / b))
		return (1);
	return (0);

}

int	check_addition_overflow(uint64_t a, uint64_t b)
{
	if ((a + b) < a)
		return (1);
	return (0);
}

int	is_inbound(t_nm *nm, uint64_t offset)
{
	if (offset > (uint64_t)nm->stat->st_size)
		return (0);
	return (1);
}
