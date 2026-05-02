/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_elf_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 18:59:16 by ndelhota          #+#    #+#             */
/*   Updated: 2026/05/02 21:14:48 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corruptor.h"


void	go_to_shstr_tab(t_corrupt *data)
{
	Elf64_Shdr	*shstr;
	
	shstr = (Elf64_Shdr *)data->shdr_begin + data->shstr_index;
}

void	go_to_elf_header(t_corrupt *data)
{
	Elf64_Ehdr	*head;

	head = (Elf64_Ehdr *)data->file_begin;
	head->e_shentsize = 312;
	data->shstr_index = head->e_shstrndx;
	data->shdr_begin = data->file_begin + head->e_shoff;
	data->header_nb = head->e_shentsize;
}
