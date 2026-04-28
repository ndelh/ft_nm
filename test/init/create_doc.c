/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_doc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 12:22:53 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/28 12:35:33 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

void	create_mine(t_data *data)
{
	if (data->true_nm == -1)
		return ;
	data->my_nm = open("my_nm", O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (data->my_nm == - 1)
		perror("my_nm file cannot be opened or created");
}

void	create_true(t_data *data)
{
	data->true_nm = open("true_nm", O_CREAT | O_RDWR, 0777);
	if (data->true_nm == - 1)
		perror("true_nm file cannot be opened or created");
}

void	create_doc(t_data *data)
{
	if (!data)
		return ;
	create_true(data);
	create_mine(data);
}
