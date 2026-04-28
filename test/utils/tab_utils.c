/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:33:06 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/28 15:00:36 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

int	tab_size(char **s)
{
	int	size;
	
	size = 0;
	if (!s)
		return (size);
	while (*s)
	{
		++size;
		++s;
	}
	return (size);
}

void	print_tab(char **s, char *name)
{
	if (name)
	{
		ft_putstr_fd("tab: ", 1);
		ft_putendl_fd(name, 1);
	}
	if (!s || !*s)
	{
		ft_putendl_fd("NULL or void tab", 1);
		return ;
	}
	while (*s)
	{
		ft_putendl_fd(*s, 1);
		++s;
	}
}

void	free_tab(char **s)
{
	char	**cursor;
	char	*tmp;

	if (!s)
		return ;
	cursor = s;
	while (*cursor)
	{
		tmp = *cursor;
		++cursor;
		free(tmp);
	}
	free(s);
}
