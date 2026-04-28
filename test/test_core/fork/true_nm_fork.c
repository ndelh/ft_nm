/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_nm_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:00:58 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/28 17:42:59 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester_core.h"

void	exec_nm(t_test *node, t_data *data)
{
	printf("entry\n");
	if (dup2(data->true_nm, STDOUT_FILENO) == -1)
	{
		perror("dup2 failed");
		ft_end(&data);
		exit(1);
	}
	close(data->true_nm);
	close(data->my_nm);
	data->true_nm = -1;
	data->my_nm = -1;
	ft_putendl_fd("in child before exec", 2);
	execve(data->nm_path, node->prog_args, data->envp);
	ft_putendl_fd("in child after exec", 2);
	perror("true nm failed to exec");
	ft_end(&data);
	exit(1);
}

void	true_nm_fork(t_test *test_node, t_data *data)
{
	pid_t	fork_t;

	fork_t = fork();
	if (!fork_t)
		exec_nm(test_node, data);
	waitpid(0, NULL, 0);
}
