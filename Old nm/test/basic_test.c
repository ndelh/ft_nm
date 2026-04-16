/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 14:09:36 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/11 14:22:56 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	g_z;

void	alloc_call(char *s)
{
	char	*c;

	c = malloc(strlen(s) + 1);
	if (!c)
		return ;
	free(c);
	c = strdup(s);
	printf("%s\n", c);
	free(c);
}

void	empty_func(void)
{
}

int	main(int ac, char **argv)
{
	if (ac != 2)
		exit(1);
	alloc_call(argv[1]);
}
