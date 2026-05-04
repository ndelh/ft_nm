/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:32:57 by ndelhota          #+#    #+#             */
/*   Updated: 2026/05/03 20:10:40 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_core.h"

void	test_core(t_data *data)
{
	standard_test(data);
	flag_test(data);
	mul_test(data);
	corruption_test(data);
}
