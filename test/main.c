/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:06:34 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/28 16:57:25 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

char	g_diff_path[] = "/usr/bin/nm";

void	init_process(t_data *data)
{
	gen_standard_file_list(data);
	if (data->standard_file_list)
		gen_standard_test_list(data);
	gen_function_tab(data);
}

int	main(int ac, char **argv, char **envp)
{
	t_data	*data;

	data = NULL;
	(void)argv;
	if (ac != 1)
	{
		ft_putendl_fd("invalid arg number", 2);
		return (1);
	}
	data_init(&data, envp);
	if (!data)
	{
		ft_end(&data);
		return (1);
	}
	if (data)
		init_process(data);
	if (data->standard_test_list)
		test_core(data);
	ft_end(&data);
	return (0);
}
