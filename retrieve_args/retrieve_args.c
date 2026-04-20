/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:05:55 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/20 18:13:07 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "retrieve_args.h"

int	no_file_case(t_data *data)
{
	char	**tab;
	char	*s;

	tab = malloc(sizeof(char *) * 2);
	if (!tab)
	{
		perror("related args malloc failed");
		return (1);
	}
	ft_memset(tab, 0, sizeof(char *)* 2);
	s = ft_strdup("a.out");
	if (!s)
	{
		perror("related args malloc failed");
		return (1);
	}
	*tab = s;
	data->file_to_nm = tab;
	return (0);
}

int copy_tab(t_data *data, char **argv)
{
	char **tab;

	tab = data->file_to_nm;
	while (*argv)
	{
		if (**argv != '-')
		{
			*tab = ft_strdup(*argv);
			if (!*tab)
			{
				perror("related to args malloc failed");
				return (1);
			}
			++tab;
		}
		++argv;
	}
	return (0);
}

int	retrieve_files(t_data *data, char **argv)
{
	char	**tab;

	if (!data->file_nb)
		return (no_file_case(data));
	tab = malloc(sizeof(char *) * (data->file_nb + 1));
	if (!tab)
	{
		perror("related to args malloc failed");
		return (1);
	}
	ft_memset(tab, 0, sizeof(char *) * (data->file_nb + 1));
	data->file_to_nm = tab;
	if (copy_tab(data, argv))
		return (1);
	return (0);
}

int	retrieve_args(t_data *data, int ac, char **argv)
{
	if (ac == 1)
		return (no_file_case(data));
	if (retrieve_flags(data, argv + 1))
		return (1);
	if (retrieve_files(data, argv + 1))
		return (1);
	return (0);
}
