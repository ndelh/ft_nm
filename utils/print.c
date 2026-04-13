/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 17:11:24 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/11 17:35:30 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_nm.h"


void	print_data(t_mn *nm)
{
	ft_putendl_fd("current data collected with fstat for the executable");
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
