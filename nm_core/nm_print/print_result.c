/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:23:24 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/27 14:25:48 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_print.h"

void	convert_hex_char(t_symbol *symbol, int size, char *s, char *base)
{
	uint64_t value;

	if (!symbol->value)
	{
		ft_memset(s, '0', size);
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

void	print_value(t_data *data, t_symbol *symbol, t_current_nm *nm, char *base)
{
	char	*result;
	int	max_size;

	if (nm->class == ELFCLASS32)
		max_size = 8;
	else
		max_size = 16;
	result = malloc(max_size + 1);
	if (!result)
		return (nm_error(data, "malloc failed while trying to create reprensation of sym value"));
	convert_hex_char(symbol, max_size, result, base);
	if (symbol->section_index == SHN_UNDEF)
		ft_memset(result, 32, max_size);
	ft_putstr_fd(result, 1);
	free(result);
}

void	display_data(t_data *data, t_symbol *symbol, t_current_nm *nm, char *base)
{
		if (data->flags & FLAG_u && symbol->section_index != SHN_UNDEF)
			return ;
		if (data->flags & FLAG_g && ELF64_ST_BIND(symbol->type_info) == STB_LOCAL)
			return ;
		print_value(data, symbol, nm, base);
		write(1, " ", 1);
		ft_putchar_fd(symbol->symbol, 1);
		write(1, " ", 1);
		ft_putendl_fd(symbol->name, 1);
		symbol = symbol->next;
}

void	print_list(t_data *data, t_symbol *symbol, t_current_nm *nm)
{
	char *base;

	if (!symbol)
		return ;
	base = ft_strdup("0123456789abcdef");
	if (!base)
		return (nm_error(data, "failed alloc for hex base"));
	while (symbol)
	{
		if ((symbol->type_info != STT_FILE && symbol->type_info != STT_SECTION) || (data->flags & FLAG_a))
			display_data(data, symbol, nm, base);
		symbol = symbol->next;
	}
	free(base);
}

void	print_result(t_data *data, t_current_nm *nm)
{
	t_symbol	*list;

	if (data->dead_nm)
		return ;
	list = nm->print_list;
	if (!list || data->file_nb > 1)
	{
		ft_putstr_fd("nm : '", 1);
		ft_putstr_fd(data->current_file, 1);
		if (!list)
			ft_putstr_fd("': ", 1);
		else
			ft_putendl_fd("':'", 1);
	}
	if (!list)
		ft_putendl_fd("no symbols", 1);
	if (data->flags & FLAG_r)
		print_in_reverse(data, list, nm);
	else
		print_list(data, list, nm);
}
