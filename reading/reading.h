/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 12:39:02 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/14 09:24:01 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READING_H
# define READING_H

# include "../ft_nm.h"

int	is_elf(t_nm *nm);
int	ft_parse_global_intel(t_nm *nm);

//parsing for security purposes
int	security_parse(t_nm *nm);

//retrieve namestring
void retrieve_namestring(t_nm *nm);

//parse_utils
int	check_multiply_overflow(uint64_t a, uint64_t b);
int	check_addition_overflow(uint64_t a, uint64_t b);
int	is_inbound(t_nm *nm, uint64_t offset);
int	is_valid_namestring(t_nm *nm);
int	parse_error(char *s);
#endif
