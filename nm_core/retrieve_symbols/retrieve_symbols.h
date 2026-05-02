/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_symbols.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:55:39 by ndelhota          #+#    #+#             */
/*   Updated: 2026/05/02 22:19:09 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RETRIEVE_SYMBOLS_H
# define RETRIEVE_SYMBOLS_H

# include "../nm_core.h"

//retrieve_symtab intels
void		retrieve_symtab_intels(t_data *data,
				t_current_nm *nm, void *cursor);
void		retrieve_symbols_name(t_data *data, t_current_nm *nm);

//retrieve loop utils
void		parse_print_intels(t_data *data, t_current_nm *nm,
				t_symbol *current);

//fetch symbol data
void		fetch_type(t_current_nm *nm, t_symbol *current);
void		retrieve_sym_loop_64(t_data *data, t_current_nm *nm);

//list_function
t_symbol	*alloc_node(t_data *data);
void		add_list(t_data *data, t_current_nm *nm);
void		add_back(t_current_nm *nm);
void		assign_name(t_data *data, t_current_nm *nm,
				t_symbol *current_symbol);

//symtab type header intels
void		parse_symtab_intels(t_data *data, t_current_nm *nm);

#endif
