/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 20:12:03 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/27 20:13:27 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_print.h"

void	print_in_reverse(t_data *data, t_symbol *symbol, t_current_nm *nm)
{
    	char *base;

	if (!symbol)
		return ;
	base = ft_strdup("0123456789abcdef");
	if (!base)
		return (nm_error(data, "failed alloc for hex base"));
	while (symbol->next)
		symbol = symbol->next;
    while (symbol)
    {
        if ((symbol->type_info != STT_FILE && symbol->type_info != STT_SECTION) || (data->flags & FLAG_a))
			display_data(data, symbol, nm, base);
		symbol = symbol->previous;
    }
	free(base);
}
