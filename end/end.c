/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:54:42 by ndelhota          #+#    #+#             */
/*   Updated: 2026/05/02 21:22:52 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "end.h"

void	free_tab(char **s)
{
	char	**erase;

	if (!s)
		return ;
	erase = s;
	while (*s)
	{
		free(*s);
		++s;
	}
	free(erase);
}

void	ft_end(t_data *data)
{
	free_tab(data->file_to_nm);
	free(data);
}
