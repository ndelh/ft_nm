/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:39:40 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/28 12:51:48 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

t_data	*alloc_data()
{
	t_data	*to_ret;

	to_ret = malloc(sizeof(t_data));
	if (!to_ret)
		return (NULL);
	ft_memset(to_ret, 0, sizeof(t_data));
	to_ret->true_nm = -1;
	to_ret->my_nm = -1;
	to_ret->nm_path = ft_strdup("/usr/bin/nm");
	if (!to_ret->nm_path)
	{
		free(to_ret);
		return (NULL);
	}
	to_ret->my_nm_path = ft_strdup("./ft_nm");
	if (!to_ret->my_nm_path)
	{
		free(to_ret->nm_path);
		free(to_ret);
		return (NULL);
	}
	return (to_ret);
}

void	data_init(t_data **data, char **envp)
{
	*data = alloc_data();
	if (!*data)
		perror("data alloc failed");
	else
		(*data)->envp = envp;
}
