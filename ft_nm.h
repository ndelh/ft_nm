/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:07:57 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/13 11:39:59 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

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
	char				*error;
	struct stat		*stat;
	void			*map_begin;
	void			*map_end;
}	t_nm;

/* init block */
t_nm	*init(char *s);


/*utils */
void	print_error(char *s);

/* read and parse */
void	read_map(t_nm* nm);

/* end_block */
void	ft_end(t_nm *nm);
#endif
