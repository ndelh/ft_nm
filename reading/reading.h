/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 12:39:02 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/13 17:24:42 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READING_H
# define READING_H

# include "../ft_nm.h"

int	is_elf(t_nm *nm);
int	ft_parse_global_intel(t_nm *nm);

//parsing for security purposes
int	security_parse(t_nm *nm);
#endif
