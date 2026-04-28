/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:46:04 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/28 16:29:27 by ndelhota         ###   ########.fr       */
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
	free_list((*data)->standard_test_list);
	free((*data)->my_nm_path);
	free((*data)->nm_path);
	free(*data);
	*data = NULL;
}
