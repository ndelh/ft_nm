/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 14:23:44 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/11 15:07:33 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	open_executable(char *s)
{
	int	to_ret;

	to_ret = open(s, O_RDONLY);
	if (to_ret == -1)
		perror("cannot open executable because");
	return (to_ret);
}

void	launch_nm(int fd)
{
	if (fd <= 0)
		return ;
}

void	ft_end(int fd)
{
	if (fd >= 0)
		close(fd);
}

int	get_size(void)
{
	int	to_ret;

	to_ret = getpagesize();
	printf("page size is: %i\n", to_ret);
	return (to_ret);
}

int	main(int ac, char **argv)
{
	int	file;

	if (ac != 2)
		return (1);
	file = open_executable(argv[1]);
	launch_nm(file);
	ft_end(file);
}
