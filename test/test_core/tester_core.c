/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:32:57 by ndelhota          #+#    #+#             */
/*   Updated: 2026/05/05 10:02:56 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_core.h"

void	printfile_name(char *s)
{
	char	*print;

	print = ft_strrchr(s, '/');
	ft_putstr_fd(BLUE, 1);
	if (!print)
		ft_putstr_fd(s, 1);
	else
	{
		++print;
		ft_putstr_fd(print, 1);
	}
	ft_putstr_fd(RESET, 1);
}

void	test_core(t_data *data)
{
	standard_test(data);
	flag_test(data);
	mul_test(data);
	corruption_test(data);
}
