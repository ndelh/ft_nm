/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_corrupted_file_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 20:23:41 by ndelhota          #+#    #+#             */
/*   Updated: 2026/05/03 20:35:50 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

void	fill_corrupted_list(char **list, t_data *data)
{
	list[0] = gen_tab_line("tested_binary/corrupted_one/corrupted_shstrtab/non_closed_content", data);
	list[1] = gen_tab_line("tested_binary/corrupted_one/corrupted_shstrtab/overflow_shstr_content", data);
	list[2] = gen_tab_line("tested_binary/corrupted_one/corrupted_shstrtab/vicious_shstrtab", data);
	list[3] = gen_tab_line("tested_binary/corrupted_one/corruptedsym/invalidsymsize", data);
	list[4] = gen_tab_line("tested_binary/corrupted_one/corruptedsym/vicious_sym_name", data);
	list[5] = gen_tab_line("tested_binary/corrupted_one/elf_corrupted/invalid_header_size", data);
	list[6] = gen_tab_line("tested_binary/corrupted_one/elf_corrupted/invalid_version", data);
	list[7] = gen_tab_line("tested_binary/corrupted_one/elf_corrupted/oob_shoff", data);
	list[8] = gen_tab_line("tested_binary/corrupted_one/elf_corrupted/oob_shstrndx", data);
	list[9] = gen_tab_line("tested_binary/corrupted_one/elf_corrupted/overlapping_shdr", data);
}

char	**alloc_corrupted_file_list(void)
{
	char	**to_ret;

	to_ret = malloc(sizeof(char *) * 21);
	if (!to_ret)
		perror("list of tested binary wasnt created");
	else
		ft_memset(to_ret, 0, sizeof(char *) * 21);
	return (to_ret);
}

void	gen_corrupted_file_list(t_data *data)
{
	char	**list;

	list = alloc_corrupted_file_list();
	if (!list)
		return ;
	fill_corrupted_list(list, data);
	data->corrupted_file_list = list;
}
