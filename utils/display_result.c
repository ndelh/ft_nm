/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:56:28 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/18 20:00:46 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_list(t_symbol *symbol)
{
	while (symbol)
	{
		printf("%zu ", symbol->value);
		printf("%c ", symbol->symbol);
		printf("%s\n", symbol->name);
		symbol = symbol->next;
	}
}

void	display_result(t_nm *nm)
{
	if (nm->print_list)
		print_list(nm->print_list);
}
