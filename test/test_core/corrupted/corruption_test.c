/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corruption_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 06:30:33 by ndelhota          #+#    #+#             */
/*   Updated: 2026/05/04 07:17:25 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester_core.h"

char	**alloc_args(t_data *data)
{
	char	**args;

	args = malloc(sizeof(char *) * 3);
	if (!args)
	{
		perror("malloc failed");
		ft_end(&data);
		exit(1);
	}
	ft_memset(args, 0, sizeof(char *) * 3);
	args[0] = data->my_nm_path;
	return (args);
}

void	corrupted_file_child(t_data *data, char **args)
{
	execve(args[0], args, data->envp);
	ft_putendl_fd("execve failed", 2);
	ft_end(&data);
	args[1] = NULL;
	free(args);
	exit(1);
}

void	fork_wait(t_data *data, char **args)
{
	pid_t	pid;
	int		wait_result;

	pid = fork();
	if (!pid)
		corrupted_file_child(data, args);
	waitpid(0, &wait_result, 0);
	if (WIFSIGNALED(wait_result))
    {
        if (WTERMSIG(wait_result) == SIGSEGV)
            ft_putendl_color(RED, "congratz for the crash (SIGSEGV)", 1);
    }
}

void	corruption_test(t_data *data)
{
	char	**args;
	char	**test_files;

	ft_putchar_fd('\n', 1);
	ft_putendl_fd("now testing invalid binary", 1);
	ft_putchar_fd('\n', 1);
	test_files = data->corrupted_file_list;
	args = alloc_args(data);
	while (*test_files)
	{
		printfile_name(*test_files);
		ft_putchar_fd('\n', 1);
		args[1] = (*test_files);
		fork_wait(data, args);
		++test_files;
		ft_putchar_fd('\n', 1);
	}
	args[1] = NULL;
	free(args);
}
