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

//utils for symbols
char	special_case(uint16_t c, unsigned char st_info);
char	retrieve_current_flags(uint64_t flags, uint32_t type);
void	list_add(t_nm *nm, char c, char *s, uint64_t value);

//utils for cmp
int		no_maj_cmp(char *s1, char *s2);

#endif
