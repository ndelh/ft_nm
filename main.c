/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 14:04:24 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/13 17:51:02 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h" 

int	main(int ac, char **argv)
{
	t_nm	*nm;

	if (ac != 2)
		return (1);
	nm = init(argv[1]);
	if (nm->map_begin)
		if (!retrieve(nm) && nm->section_header_nb)
			seek_symbols(nm);
	display_result(nm);
	ft_end(nm);
}
