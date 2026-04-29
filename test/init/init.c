/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:39:40 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/29 23:34:17 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

t_data	*alloc_data(void)
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

void	alloc_flag_line(t_data *data)
{
	data->flag_line = ft_strdup("aupgr");
	if (!data->flag_line)
	{
		perror("failed_init_alloc");
		ft_end(&data);
		exit(1);
	}
}

void	data_init(t_data **data, char **envp)
{
	*data = alloc_data();
	if (!*data)
	{
		perror("data alloc failed");
		return ;
	}
	(*data)->envp = envp;
	alloc_flag_line(*data);
}
