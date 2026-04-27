/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:39:50 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/27 13:45:44 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "retrieve_symbols.h"

void	assign_name(t_data *data, t_current_nm *nm, t_symbol *current_symbol)
{
	current_symbol->name = ft_strdup(nm->sym_name + current_symbol->name_index);
	if (!current_symbol->name)
		return (nm_error(data, "failed alloc when tying to dup sym_name"));
}
