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

typedef struct s_nm
{
	int				fd;
	int				fstat_result;
	int				page_size;
	int				arch_type;
	int				version;
	int				endian;
	int				osabi;
	uint64_t		section_offset;
	uint64_t		entry_number;
	uint64_t		table_name;
	uint64_t		section_size;
	uint64_t		header_name_size;
	uint64_t		string_tab_size;
	char			*string_tab;
	char			*header_name;
	struct stat		*stat;
	void			*map_begin;
	void			*map_end;
	void			*section_begin;
}	t_nm;

/* init block */
t_nm	*init(char *s);


/*utils */
void	print_error(char *s);
void	print_simple_error(char *s);

/* read and parse */
void	read_map(t_nm* nm);

/*symbols */
void	symbols(t_nm *nm);

/* end_block */
void	ft_end(t_nm *nm);
#endif
