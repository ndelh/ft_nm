/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_core.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:43:47 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/20 19:45:10 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_CORE_H
# define NM_CORE_H

# include "../ft_nm.h"

//init
void	init_nm(t_data *data);

//end

void	end_nm(t_data *data, t_current_nm *current_nm);

//error
void	nm_error(t_data *data, char *s);

//header intels check
void    add_overflow(uint64_t a, u_int64_t b, char *s, t_data *data);
void    mul_overflow(uint64_t a, u_int64_t b, char *s, t_data *data);

#endif
