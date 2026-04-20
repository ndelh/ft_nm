/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:17:45 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/16 15:18:50 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RETRIEVE_H
#define RETRIEVE_H

# include "../ft_nm.h"

//retrieve first data
int retrieve_16_bytes(t_nm *nm);

//retrieve header data
int fetch(t_nm *nm);

//retrieve shstr content
int	retrieve_shstr_content(t_nm *nm);

#endif
