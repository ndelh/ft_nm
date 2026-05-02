/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corruptor.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:34:46 by ndelhota          #+#    #+#             */
/*   Updated: 2026/05/02 20:46:29 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORRUPTOR_H
# define CORRUPTOR_H

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
# include <stdint.h>
# include "../../lib/libft/libft.h"

typedef	struct	s_corrupt
{
	int	fd;
	void	*file_begin;
    	void    *shdr_begin;
    	struct stat	*stat;
    	uint64_t    file_size;
    	int         shstr_index;
    	int         header_nb;

}	t_corrupt;

//init
void    open_map(t_corrupt *data);

//travelling

void	go_to_elf_header(t_corrupt *data);

//end
void	ft_end(t_corrupt *data, int exit_code, char *s);

#endif
