/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_popen_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:12:31 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/29 13:43:09 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester_core.h"

void	popen_read(t_data *data, char **args, int read_end, int write_end)
{
	close(read_end);
	if (dup2(write_end, STDOUT_FILENO) == -1)
	{
		close(write_end);
		perror("failed dup2 in diff fork");
		ft_end(&data);
		exit(0);
	}
	close(write_end);
	execve(args[0], args, data->envp);
	perror("missed execve in diff fork");
	ft_end(&data);
	exit(1);
}

int	diff_launch(t_data *data)
{
	int	pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
	{
		perror("cannot open pipe for popen_read");
		ft_end(&data);
		exit(1);
	}
	pid = fork();
	if (!pid)
		popen_read(data, data->diff_tab, pipe_fd[0], pipe_fd[1]);
	waitpid(0, NULL, 0);
	close(pipe_fd[1]);
	return (pipe_fd[0]);
}

void	diff_test(t_data *data, t_test *node)
{
	int	result;
	int	read_nb;
	char	buff[2];

	(void)node;
	result = diff_launch(data);
	read_nb = read(result, buff, 1);
	ft_putstr_fd("tested binary: ", 1);
	ft_putendl_fd(node->prog_path, 1);
	if (read_nb == -1)
		ft_putendl_fd("error while reading from custom popen returned fd", 2);
	else if (read_nb)
		ft_putendl_fd("diff ko", 1);
	else
		ft_putendl_fd("success", 1);
	close(result);

}

