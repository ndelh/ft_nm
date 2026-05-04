/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 14:04:24 by ndelhota          #+#    #+#             */
/*   Updated: 2026/05/04 07:30:19 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h" 

int	alloc_data(t_data **data)
{
	*data = malloc(sizeof(t_data));
	if (!data)
	{
		perror("failed to allocate main_struct");
		return (1);
	}
	ft_memset(*data, 0, sizeof(t_data));
	return (0);
}

int	main(int ac, char **argv)
{
	t_data	*data;

	data = NULL;
	if (alloc_data(&data))
		return (1);
	if (!retrieve_args(data, ac, argv))
		nm_loop(data);
	ft_end(data);
}
