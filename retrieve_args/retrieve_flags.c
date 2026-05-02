/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:18:56 by ndelhota          #+#    #+#             */
/*   Updated: 2026/05/02 21:31:53 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "retrieve_args.h"

int	unsupported_char(char *s)
{
	ft_putstr_fd("nm: invalid option -- '", 2);
	ft_putchar_fd(*s, 2);
	ft_putendl_fd("'", 2);
	return (1);
}

int	active_flags(t_data *data, char *s)
{
	++s;
	while (*s)
	{
		if (*s == 'a')
			data->flags |= FLAG_A;
		else if (*s == 'g')
			data->flags |= FLAG_G;
		else if (*s == 'u')
			data->flags |= FLAG_U;
		else if (*s == 'r')
			data->flags |= FLAG_R;
		else if (*s == 'p')
			data->flags |= FLAG_P;
		else
			return (unsupported_char(s));
		++s;
	}
	return (0);
}

int	retrieve_flags(t_data *data, char **argv)
{
	while (*argv)
	{
		if (**argv != '-')
			data->file_nb++;
		else
			if (active_flags(data, *argv))
				return (1);
		++argv;
	}
	return (0);
}
