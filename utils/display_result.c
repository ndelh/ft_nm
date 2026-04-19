/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:56:28 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/19 11:53:17 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	convert_hex_char(t_symbol *symbol, int size, char *s, char *base)
{
	uint64_t value;

	if (!symbol->value)
	{
		ft_memset(s, 32, size);
		s[size] = 0;
		return ;
	}
	value = symbol->value;
	ft_memset(s, 48, size);
	s += size;
	*s = 0;
	while (value)
	{
		--s;
		*s = base[value % 16];
		value /= 16;
	}

}

void	print_value(t_symbol *symbol, t_nm *nm, char *base)
{
	char	*result;
	int	max_size;

	if (nm->class == ELFCLASS32)
		max_size = 8;
	else
		max_size = 16;
	result = malloc(max_size + 1);
	if (!result)
		return ;
	convert_hex_char(symbol, max_size, result, base);
	ft_putstr_fd(result, 1);
	write(1, " ", 1);
	free(result);
}

void	print_list(t_symbol *symbol, t_nm *nm)
{
	char *base;

	base = ft_strdup("0123456789abcdef");
	if (!base)
		return ;
	while (symbol)
	{
		print_value(symbol, nm, base);
		printf("%c ", symbol->symbol);
		printf("%s\n", symbol->name);
		symbol = symbol->next;
	}
	free(base);
}

void	display_result(t_nm *nm)
{
	if (nm->print_list)
		print_list(nm->print_list, nm);
}
