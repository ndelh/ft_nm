/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:46:04 by ndelhota          #+#    #+#             */
/*   Updated: 2026/05/03 19:26:25 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

void	close_fd(t_data *data)
{
	if (data->true_nm != -1)
		close(data->true_nm);
	if (data->my_nm != -1)
		close(data->my_nm);
}

void	ft_end(t_data **data)
{
	if (!*data || !data)
		return ;
	close_fd(*data);
	free_tab((*data)->standard_file_list);
	free_tab((*data)->corrupted_file_list);
	free_tab((*data)->diff_tab);
	free_tab((*data)->flag_tab);
	free_tab((*data)->multi_file_tab);
	free_list((*data)->standard_test_list);
	free((*data)->my_nm_path);
	free((*data)->nm_path);
	free((*data)->flag_line);
	free(*data);
	*data = NULL;
}
