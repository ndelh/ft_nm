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
# include "./lib/libft/libft.h"

typedef	struct s_symbol
{
	uint64_t 		value;
	char 			*name;
	char			symbol;
	struct s_symbol *next;
} t_symbol;

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
	struct stat		*stat;
	void			*map_begin;
	void			*map_end;
	t_symbol		*print_list;
}	t_nm;

/* init block */
t_nm	*init(char *s);


/* utils */
void	print_error(char *s);
void	print_simple_error(char *s);
int add_overflow(uint64_t a, uint64_t b, char *s);
int mul_overflow(uint64_t a, uint64_t b, char *s);
int	add_range_overflow(uint64_t offset, uint64_t struct_size, uint64_t struct_nb, char *s);
int	is_section_out(t_nm *nm, uint64_t offset, uint64_t struct_size, uint64_t struct_nb, char *s);
int	is_offset_out(t_nm *nm, uint64_t offset, char *s);
void	display_result(t_nm *nm);
/*debug*/

void	print_strtab(char *s, uint64_t size);

/* retrieve*/
int	retrieve(t_nm *nm);
/*	seek_symbols */
void	seek_symbols(t_nm *nm);

/* end_block */
void	ft_end(t_nm *nm);

#endif