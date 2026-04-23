/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_symbols.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:55:39 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/23 11:56:27 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RETRIEVE_SYMBOLS_H
# define RETRIEVE_SYMBOLS_H

# include "../nm_core.h"

//retrieve_symtab intels
void	retrieve_symtab_intels(t_data *data, t_current_nm *nm, void *cursor);

//symtab type header intels

void    parse_symtab_intels(t_data *data, t_current_nm *nm);

#endif
