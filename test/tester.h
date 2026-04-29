/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:07:19 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/28 17:22:09 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

# include <sys/types.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include "lib/libft/libft.h"

extern char	g_diff_path[];

typedef struct s_pipe
{
	int				read;
	int				write;
}	t_pipe;

typedef struct s_test
{
	int				test_nb;
	char			*prog_path;
	char			**prog_args;
	struct s_test	*next;
}	t_test;

typedef struct s_data
{
	char			**envp;
	char			**standard_file_list;
	char			**diff_tab;
	char			*nm_path;
	char			*my_nm_path;
	int				true_nm;
	int				my_nm;
	t_test			*standard_test_list;
}	t_data;

//init
void	data_init(t_data **data, char **envp);
void	gen_standard_file_list(t_data *data);
void	gen_function_tab(t_data *data);
char	*gen_tab_line(char *s, t_data *data);
int	gen_standard_test_list(t_data *data);
//end
void	ft_end(t_data **data);

//tab_utils
int	tab_size(char **s);
void	print_tab(char **s, char *name);
void	free_tab(char **s);

//list_utils
void	insert_last(t_test **list, t_test *insert);
void	free_list(t_test *list);

//test_core
void	test_core(t_data *data);

#endif
