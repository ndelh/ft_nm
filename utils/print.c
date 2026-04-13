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

#include "../ft_nm.h"

void	print_simple_error(char *s)
{
	ft_putendl_fd(s, 2);
}

void	print_error(char *s)
{
	char *a;

	a = strerror(errno);
	if (s)
	{
		ft_putendl_fd(s, 2);
		ft_putchar_fd(32, 2);
	}
	ft_putendl_fd(a, 2);
}
