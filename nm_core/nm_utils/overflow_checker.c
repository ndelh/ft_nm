/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:31:17 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/21 18:31:55 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_utils.h"


void    add_overflow(uint64_t a, u_int64_t b, char *s, t_data *data)
{
    	if (b <= 0xFFFFFFFFFFFFFFFF - a)
		    return ;
        nm_error(data, s);
}

void    mul_overflow(uint64_t a, u_int64_t b, char *s, t_data *data)
{
        if (!a || !b)
            return ;
        if (a <= 0xFFFFFFFFFFFFFFFF / b)
            return ;
        nm_error(data, s);
}