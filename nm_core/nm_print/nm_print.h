/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:03:09 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/20 20:04:07 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_PRINT_H
# define NM_PRINT_H

# include "../nm_core.h"

void	print_in_reverse(t_data *data, t_symbol *symbol, t_current_nm *nm);
void	display_data(t_data *data, t_symbol *symbol, t_current_nm *nm, char *base);

#endif
