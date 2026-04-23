/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_init.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:54:56 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/20 19:56:04 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_INIT_H
# define NM_INIT_H

#include "../nm_core.h"

void	retrieve_basic(t_data *data, t_current_nm *nm);
void	fetch_shstr_intels(t_data *data, t_current_nm *nm);

//parsing
void	parse_first_char_intel(t_data *data, t_current_nm *nm);
void    parse_shdr_intels(t_data *data, t_current_nm *nm);

#endif
