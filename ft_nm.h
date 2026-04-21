/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:07:57 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/14 14:05:00 by ndelhota         ###   ########.fr       */
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

# define FLAG_a (1 << 0)
# define FLAG_g (1 << 1)
# define FLAG_u (1 << 2)
# define FLAG_r (1 << 3)
# define FLAG_p (1 << 4)

typedef	struct s_symbol
{
	uint64_t 		value;
	char 			*name;
	char			symbol;
	struct s_symbol *next;
} t_symbol;

typedef struct s_current_nm
{
	int	fd;
	//file intels
	int class;
	int version;
	int	endian;
	int	osabi;
	uint64_t		section_header_offset;
	uint64_t		section_header_nb;
	uint64_t		section_header_size;
	//shstr intels
	uint64_t		shstr_index;
	uint64_t		shstr_content_offset;
	uint64_t		shstr_content_size;
	uint64_t		string_tab_size;
	char			*header_name;
	//map intels
	struct stat		*stat;
	void			*map_begin;
	uint64_t		file_size;
	struct t_symbol	*print_list;


} t_current_nm;

typedef struct s_data
{
	unsigned char			flags;
	int						file_nb;
	char					**file_to_nm;
	char					*current_file;
	struct s_current_nm		*current_nm;
	bool					dead_nm;
	
}	t_data;


typedef struct s_nm
{
	int				fd;
	int				fstat_result;
	int				page_size;
	int				class;
	int				version;
	int				endian;
	int				osabi;
	int				must_exit;
	uint64_t		file_size;
	uint64_t		elf_header_size;
	uint64_t		section_header_offset;
	uint64_t		section_header_nb;
	uint64_t		section_header_size;
	uint64_t		section_header_string_table_index;
	uint64_t		shstr_content_offset;
	uint64_t		shstr_content_size;
	uint64_t		string_tab_size;
	char			*string_tab;
	char			*header_name;
	unsigned char	flags;
	struct stat		*stat;
	void			*map_begin;
	void			*map_end;
	char			**files_to_nm;
	int				file_nb;
	t_symbol		*print_list;
}	t_nm;

//args retrieving and flags settings
int	retrieve_args(t_data *data, int ac, char **argv);

//nm_core
void	nm_loop(t_data *data);

//end
void	ft_end(t_data *data);

#endif