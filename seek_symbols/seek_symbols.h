/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seek_symbols.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:32:16 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/16 19:33:25 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEEK_SYMBOLS_H
# define SEEK_SYMBOLS_H

# include "../ft_nm.h"

int	safety_section_header_loop(t_nm *nm);

int	parse_sh_link(t_nm *nm, uint64_t index);

int retrieve_symtab_intel_64(t_nm *nm);

#endif
