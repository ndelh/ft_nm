/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:04:40 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/20 20:09:51 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_print.h"

void	nm_error(t_data *data, char *s)
{
	ft_putstr_fd("nm : '", 2);
	ft_putstr_fd(data->current_file, 2);
	ft_putstr_fd("': ", 2);
	if (s)
		ft_putendl_fd(s, 2);
	else
		perror(NULL);
	data->dead_nm = 1;
}
