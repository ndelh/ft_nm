/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_flag_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 22:29:59 by ndelhota          #+#    #+#             */
/*   Updated: 2026/05/02 23:39:13 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

void	simple_flags(t_data *data, char **flag_tab)
{
	flag_tab[0] = gen_tab_line("-a", data);
	flag_tab[1] = gen_tab_line("-u", data);
	flag_tab[2] = gen_tab_line("-p", data);
	flag_tab[3] = gen_tab_line("-g", data);
	flag_tab[4] = gen_tab_line("-r", data);
	flag_tab[5] = gen_tab_line("-ar", data);
	flag_tab[6] = gen_tab_line("-ra", data);
	flag_tab[7] = gen_tab_line("-pg", data);
	flag_tab[8] = gen_tab_line("-pr", data);
	flag_tab[9] = gen_tab_line("-ur", data);
}

int	consult_urandom(t_data *data, int fd, int modulo)
{
	unsigned char	c[1];
	int				nb_read;
	int				result;

	nb_read = read(fd, c, 1);
	if (nb_read == -1)
	{
		perror("error while reading urandom");
		close(fd);
		ft_end(&data);
		exit(1);
	}
	result = c[0] % modulo;
	return (result);
}

char	*gen_complex_flags_line(t_data *data, int rand_fd)
{
	char	*line;
	int		it;

	line = malloc(sizeof(char) * 6);
	if (!line)
	{
		perror("alloc failed while trying to gen random part of flag tab");
		ft_end(&data);
		close(rand_fd);
		exit(1);
	}
	ft_memset(line, 0, sizeof(char) * 6);
	*line = '-';
	it = 1;
	while (it < 5)
	{
		line[it] = data->flag_line[consult_urandom(data, rand_fd, 5)];
		++it;
	}
	return (line);
}

void	fill_flag_tab(t_data *data)
{
	int	rand_fd;
	int	i;

	rand_fd = open("/dev/urandom", O_RDONLY);
	if (rand_fd == -1)
	{
		perror("cannot open /dev/urandom for randomized test purpose");
		ft_end(&data);
	}
	simple_flags(data, data->flag_tab);
	i = 10;
	while (i < 20)
	{
		data->flag_tab[i] = gen_complex_flags_line(data, rand_fd);
		++i;
	}
	close(rand_fd);
}

void	gen_flag_tab(t_data *data)
{
	data->flag_tab = malloc(sizeof(char *) * 21);
	if (!data->flag_tab)
	{
		ft_end(&data);
		exit(1);
	}
	ft_memset(data->flag_tab, 0, sizeof(char *) * 21);
	fill_flag_tab(data);
}
