/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corruptor_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:33:02 by ndelhota          #+#    #+#             */
/*   Updated: 2026/05/02 18:19:22 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corruptor.h"

void	alloc_open(t_corrupt **data, char *filename)
{
	int fd;
	t_corrupt *allocated;

	fd = open(filename, O_RDWR);
	if (fd == -1)
	{
		perror("error while opening file");
		exit(1);
	}
	allocated = malloc(sizeof(t_corrupt));
	if (!allocated)
	{
		close(fd);
		perror("malloc failed");
		exit(1);
	}
	ft_memset(allocated, 0, sizeof(t_corrupt));
	allocated->fd = fd;
	*data = allocated;
}

void	ft_end(t_corrupt *data, int exit_code, char *s)
{
	if (exit_code)
	{
		perror("exited because of");
		ft_putstr_fd("error caused on ", 2);
		ft_putendl_fd(s, 2);
	}
	if (data->stat)
		free(data->stat);
	if (data->file_begin && data->file_begin != MAP_FAILED)
		munmap(data->file_begin, data->file_size);
	close(data->fd);
	free(data);
	exit(exit_code);
}

int	main(int ac, char **argv)
{
	t_corrupt	*data;

	if (ac != 2)
	{
		ft_putendl_fd("invalid arg number", 2);
		return (1);
	}
	alloc_open(&data, argv[1]);
	open_map(data);
	go_to_elf_header(data);
	ft_end(data, 0, NULL);
}
