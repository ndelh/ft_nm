/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_standard_file_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:20:39 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/28 15:01:16 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

void	fill_list(char **list)
{
	list[0] = ft_strdup("tested_binary/minishell");
	list[1] = ft_strdup("ft_nm");
	list[2] = ft_strdup("tested_binary/nm_target");
}

char	**alloc_file_list(void)
{
	char **to_ret;

	to_ret = malloc(sizeof(char *) * 21);
	if (!to_ret)
		perror("list of tested binary wasnt created");
	else
		ft_memset(to_ret, 0, sizeof(char *) * 21);
	return (to_ret);
}

void	gen_standard_file_list(t_data *data)
{
	char	**list;
	
	list = alloc_file_list();
	if (!list)
		return ;
	fill_list(list);
	data->standard_file_list = list;
}
