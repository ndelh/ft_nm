/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:45:41 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/28 18:30:33 by ndelhota         ###   ########.fr       */
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
	print_tab(data->flag_tab, "data flag tab");
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
