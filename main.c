/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 14:04:24 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/13 17:51:02 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h" 

void	clean_struct(t_nm *nm)
{
	close_fd(nm);
	close_map(nm);
	free(nm->stat);
	free_list(nm->print_list);
	nm->fd = 0;
	nm->map_begin = NULL;
	nm->stat = NULL;
	nm->print_list = NULL;

}

void	launch_nm_loop(t_nm *nm)
{
	char **tab;
	
	tab =  nm->files_to_nm;
	while (*tab)
	{
		if (nm->file_nb > 1)
		{
			write(1, "\n", 1);
			ft_putstr_fd(*tab, 1);
			ft_putendl_fd(":", 1);
		}
		open_file(nm, *tab);
		if (nm->fd != -1)
		{
			fetch_stat(nm);
			memory_init(nm);
		}

		if (!retrieve(nm) && nm->section_header_nb)
			seek_symbols(nm);
		display_result(nm);
		clean_struct(nm);
		++tab;
	}
}

int	main(int ac, char **argv)
{
	t_nm	*nm;

	if (ac < 2)
	{
		print_simple_error("nm: not enought arguments");
		return (1);
	}

	nm = init(argv);
	if (nm->map_begin)
		if (!retrieve(nm) && nm->section_header_nb)
			seek_symbols(nm);
	if (!nm->must_exit)
		launch_nm_loop(nm);
	ft_end(nm);
}
