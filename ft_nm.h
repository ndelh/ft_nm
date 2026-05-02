/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:07:57 by ndelhota          #+#    #+#             */
/*   Updated: 2026/05/02 22:36:34 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include <elf.h>
# include <sys/mman.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdbool.h>
# include "./lib/libft/libft.h"

# define FLAG_A 1 
# define FLAG_G 2
# define FLAG_U 4
# define FLAG_R 8
# define FLAG_P 16

typedef struct s_symbol
{
	uint64_t		value;
	uint64_t		name_index;
	uint16_t		section_index;
	uint64_t		flags;
	uint32_t		type;
	char			*name;
	char			symbol;
	unsigned char	type_info;
	uint64_t		sym_size;
	struct s_symbol	*next;
	struct s_symbol	*previous;
}	t_symbol;

typedef struct s_current_nm
{
	int				fd;
	//file intels
	int				class;
	int				version;
	int				endian;
	int				osabi;
	uint64_t		section_header_offset;
	uint64_t		section_header_nb;
	uint64_t		section_header_size;
	//shstr intels
	uint64_t		shstr_index;
	uint64_t		shstr_content_offset;
	uint64_t		shstr_content_size;
	uint64_t		string_tab_size;
	char			*header_name;
	//symtab intel
	uint64_t		symtab_content_offset;
	uint64_t		symtab_content_size;
	uint64_t		sym_name_index;
	uint64_t		str_sym_name_offset;
	uint64_t		str_sym_name_size;
	uint64_t		symstruct_size;
	char			*sym_name;
	//map intels
	struct stat		*stat;
	void			*map_begin;
	uint64_t		file_size;
	t_symbol		*print_list;
	t_symbol		*current;
}	t_current_nm;

typedef struct s_data
{
	unsigned char			flags;
	int						file_nb;
	char					**file_to_nm;
	char					*current_file;
	struct s_current_nm		*current_nm;
	bool					dead_nm;

}	t_data;

//args retrieving and flags settings
int		retrieve_args(t_data *data, int ac, char **argv);

//nm_core
void	nm_loop(t_data *data);

//end
void	ft_end(t_data *data);

#endif
