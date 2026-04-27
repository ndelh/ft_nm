/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 17:11:24 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/13 11:38:04 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_strtab(char *s, uint64_t size)
{
	while (size)
	{
		if (!*s)
			write(1, "\n", 1);
		else
			write(1, s, 1);
		++s;
		--size;
	}
}

void	print_simple_error(char *s)
{
	ft_putendl_fd(s, 2);
}

