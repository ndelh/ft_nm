/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_standard_file_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:20:39 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/29 23:33:05 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

void	fill_list(char **list, t_data *data)
{
	list[0] = gen_tab_line("tested_binary/minishell", data);
	list[1] = gen_tab_line("ft_nm", data);
	list[2] = gen_tab_line("tested_binary/nm_target", data);
	list[3] = gen_tab_line("nm_tester", data);
	list[4] = gen_tab_line("tested_binary/ircserv", data);
	list[5] = gen_tab_line("tested_binary/librraudit_32.so", data);
	list[6] = gen_tab_line("tested_binary/libextnet.so", data);
}

char	**alloc_file_list(void)
{
	char	**to_ret;

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
	fill_list(list, data);
	data->standard_file_list = list;
}
