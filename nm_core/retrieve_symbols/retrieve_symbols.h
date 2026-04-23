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
void	retrieve_symbols_name(t_data *data, t_current_nm *nm);

//retrieve loop utils
int     alloc_print_node(t_data *data, t_current_nm *nm);
void	parse_print_intels(t_data *data, t_current_nm *nm, t_symbol *current);

//fetch symbol data
void	fetch_type(t_current_nm *nm, t_symbol *current);

//symtab type header intels

void    parse_symtab_intels(t_data *data, t_current_nm *nm);

#endif
