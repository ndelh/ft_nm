/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_doc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 12:22:53 by ndelhota          #+#    #+#             */
/*   Updated: 2026/05/03 16:35:53 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester_core.h"

void	create_mine(t_data *data)
{
	if (data->true_nm == -1)
		return ;
	data->my_nm = open("my_nm", O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (data->my_nm == -1)
		perror("my_nm file cannot be opened or created");
}

void	create_true(t_data *data)
{
	data->true_nm = open("true_nm", O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (data->true_nm == -1)
		perror("true_nm file cannot be opened or created");
}

void	close_doc(t_data *data)
{
	if (data->true_nm != -1)
	{
		close(data->true_nm);
		data->true_nm = -1;
	}
	if (data->my_nm != -1)
	{
		close(data->my_nm);
		data->my_nm = -1;
	}
}

void	create_doc(t_data *data)
{
	create_true(data);
	create_mine(data);
	if (data->my_nm == -1 || data->true_nm == -1)
	{
		ft_end(&data);
		exit(0);
	}
}
