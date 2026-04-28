/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_standard_test_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:14:03 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/28 17:24:30 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

int	alloc_attribute_node_content(t_test *node, char *s, char *nm_path)
{
	char	**tab;
	
	tab = malloc(sizeof(char *) * 10);
	if (!tab)
	{
		free(node);
		return (1);
	}
	ft_memset(tab, 0, sizeof(char *) * 10);
	tab[0] = nm_path;
	tab[1] = s;
	node->prog_path = s;
	node->prog_args = tab;
	return (0);
}

t_test	*alloc_node(char *s, char *nm_path)
{
	t_test	*to_ret;

	to_ret = malloc(sizeof(t_test));
	if (!to_ret)
		return NULL;
	ft_memset(to_ret, 0, sizeof(t_test));
	if (alloc_attribute_node_content(to_ret, s, nm_path))
		return NULL;
	return (to_ret);
}

int	gen_standard_test_list(t_data *data)
{
	t_test	*to_insert;
	char	**tab;

	tab = data->standard_file_list;
	while (*tab)
	{
		to_insert = alloc_node(*tab, data->nm_path);
		if (!to_insert)
		{
			perror("malloc failed while creating node");
			return (1);
		}
		insert_last(&data->standard_test_list, to_insert);
		++tab;
	}
	return (0);
}
