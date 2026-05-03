/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:45:41 by ndelhota          #+#    #+#             */
/*   Updated: 2026/05/03 20:00:40 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester_core.h"

void	standard_test(t_data *data)
{
	t_test	*list;

	list = data->standard_test_list;
	while (list)
	{
		create_doc(data);
		list->prog_args[0] = data->nm_path;
		true_nm_fork(list, data);
		list->prog_args[0] = data->my_nm_path;
		my_nm_fork(list, data);
		close_doc(data);
		diff_test(data, list, NULL);
		list = list->next;
	}
}

void	flag_test(t_data *data)
{
	t_test	*list;
	char	**flags;

	list = data->standard_test_list;
	while (list)
	{
		flags = data->flag_tab;
		while (*flags)
		{
			list->prog_args[2] = *flags;
			create_doc(data);
			list->prog_args[0] = data->nm_path;
			true_nm_fork(list, data);
			list->prog_args[0] = data->my_nm_path;
			my_nm_fork(list, data);
			close_doc(data);
			diff_test(data, list, *flags);
			++flags;
		}
		list->prog_args[2] = NULL;
		list = list->next;
	}
}

void	mul_test(t_data *data)
{
	char	**flags;

	flags = data->flag_tab;
	ft_putendl_fd("multiple file test:", 1);
	free(data->multi_file_tab[0]);
	while (*flags)
	{
		data->multi_file_tab[3] = *flags;
		create_doc(data);
		data->multi_file_tab[0] = data->nm_path;
		true_nm_fork_mul(data);
		data->multi_file_tab[0] = data->my_nm_path;
		my_nm_fork_mul(data);
		close_doc(data);
		diff_mull_test(data, *flags);
		++flags;
	}
	data->multi_file_tab[3] = NULL;
	data->multi_file_tab[0] = ft_strdup("a");
}
