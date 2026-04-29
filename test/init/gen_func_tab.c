/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_func_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:48:01 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/29 23:34:32 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

char	*gen_tab_line(char *s, t_data *data)
{
	char	*to_ret;

	to_ret = ft_strdup(s);
	if (!to_ret)
	{
		perror("failed malloc while constructing tab");
		ft_end(&data);
		exit(1);
	}
	return (to_ret);
}

void	gen_diff_tab(t_data *data)
{
	char	**diff_tab;

	diff_tab = malloc(sizeof(char *) * 4);
	if (!diff_tab)
	{
		perror("failed malloc while constructing tab");
		ft_end(&data);
		exit(1);
	}
	ft_memset(diff_tab, 0, sizeof(char *) * 4);
	diff_tab[0] = gen_tab_line("/usr/bin/diff", data);
	diff_tab[1] = gen_tab_line("true_nm", data);
	diff_tab[2] = gen_tab_line("my_nm", data);
	diff_tab[3] = NULL;
	data->diff_tab = diff_tab;
}

void	gen_function_tab(t_data *data)
{
	gen_diff_tab(data);
}
