/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_16_bytes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:26:41 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/16 16:15:07 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "retrieve.h"

/* must try with a simple strrncmp and ELFMAG, SELFMAG */
int	check_type(unsigned char *e_ident)
{
	if (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1
		|| e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3)
	{
		ft_putendl_fd("Error: file cannot be identied as an ELF File", 2);
		return (1);
	}
	return (0);
}

int	retrieve_class(unsigned char *e_ident, t_nm *nm)
{
	if (e_ident[EI_CLASS] == ELFCLASS32 || e_ident[EI_CLASS] == ELFCLASS64)
	{
		nm->class = e_ident[EI_CLASS];
		return (0);
	}
	ft_putendl_fd("Error: unknown architecture, must be 64 or 32 bytes", 2);
	return (1);
}

int	retrieve_endian(unsigned char *e_ident, t_nm *nm)
{
	if (e_ident[EI_DATA] == ELFDATA2LSB || e_ident[EI_DATA] == ELFDATA2MSB)
	{
		nm->endian = e_ident[EI_DATA];
		return (0);
	}
	ft_putendl_fd("error: unknown endian type", 2);
	return (1);
}

int	retrieve_version(unsigned char *e_ident)
{
	if (e_ident[EI_VERSION] != 1)
	{
		ft_putendl_fd("Error: file version does not exist", 2);
		return (1);
	}
	return (0);
}

int	retrieve_16_bytes(t_nm *nm)
{
	Elf64_Ehdr	*header;
	unsigned char		*e_ident;

	header = (Elf64_Ehdr *)nm->map_begin;
	e_ident = header->e_ident;
	if (check_type(e_ident) || retrieve_class(e_ident, nm)
		|| retrieve_endian(e_ident, nm) || retrieve_version(e_ident))
		return (1);
	return (0);
}
