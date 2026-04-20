/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 16:09:46 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/19 16:14:21 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int	unsupported_char(char *s)
{
	ft_putstr_fd("nm: invalid option -- '", 2);
	ft_putchar_fd(*s, 2);
	ft_putendl_fd("'", 2);
	return (1);
}
