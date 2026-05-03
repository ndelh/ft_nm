/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_nm_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:33:19 by ndelhota          #+#    #+#             */
/*   Updated: 2026/05/03 19:55:42 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester_core.h"

void	exec_my_nm(t_test *node, t_data *data)
{
	if (dup2(data->my_nm, STDOUT_FILENO) == -1)
	{
		ft_end(&data);
		exit(1);
	}
	close_doc(data);
	data->true_nm = -1;
	execve(data->my_nm_path, node->prog_args, data->envp);
	perror("my_nm failed to exec");
	ft_end(&data);
	exit(1);
}

void	my_nm_fork(t_test *test_node, t_data *data)
{
	pid_t	fork_t;

	fork_t = fork();
	if (!fork_t)
		exec_my_nm(test_node, data);
	waitpid(0, NULL, 0);
}

void	exec_my_nm_mul(t_data *data)
{
	if (dup2(data->my_nm, STDOUT_FILENO) == -1)
	{
		ft_end(&data);
		exit(1);
	}
	close_doc(data);
	data->true_nm = -1;
	execve(data->my_nm_path, data->multi_file_tab, data->envp);
	perror("my_nm failed to exec");
	ft_end(&data);
	exit(1);
}

void	my_nm_fork_mul(t_data *data)
{
	pid_t	fork_t;

	fork_t = fork();
	if (!fork_t)
		exec_my_nm_mul(data);
	waitpid(0, NULL, 0);
}
