/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_symtab_intel.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 15:25:54 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/18 15:27:29 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "seek_symbols.h"

char    assign_value_64(t_nm *nm, Elf64_Sym *current_sym)
{
    char        to_ret;
    Elf64_Shdr  *target;

    to_ret = special_case(current_sym->st_shndx, current_sym->st_info);
    if (!to_ret)
    {
        target = (Elf64_Shdr *)((char *)nm->map_begin + nm->section_header_offset +
        (current_sym->st_shndx * nm->section_header_size));
        to_ret = retrieve_current_flags(target->sh_flags, target->sh_type);
    }
    if (to_ret != 'U' && ELF64_ST_BIND(current_sym->st_info) == STB_LOCAL)
        to_ret = ft_tolower(to_ret);
    return (to_ret);
}

void    assign_sym_64(t_nm *nm, Elf64_Shdr *sym, char *strtab)
{
    Elf64_Sym   *current_sym;
    uint64_t    it;
    char        c;
    char        *s;
    unsigned char   type;

    current_sym = (Elf64_Sym *)((char *)nm->map_begin + (sym->sh_offset));
    it = sym->sh_size / sym->sh_entsize;
    if (it)
    {
        current_sym = (Elf64_Sym *)((char *)current_sym + sym->sh_entsize);
        --it;
    }
    while (it)
    {
        --it;
        type = ELF64_ST_TYPE(current_sym->st_info);
        if ((type != STT_FILE && type != STT_SECTION) || (nm->flags & FLAG_a))
        {
            c = assign_value_64(nm, current_sym);
            s = retrieve_name_value_64(type, current_sym, strtab, nm);
            list_add(nm, c, s, current_sym->st_value);
        }
        current_sym = (Elf64_Sym *)((char *)current_sym + sym->sh_entsize);
    }
}

void    fetch_symtab_data_64(t_nm *nm, Elf64_Shdr *cursor)
{
    Elf64_Shdr  *linked_strtab;
    char        *str_tab;
    uint64_t    str_size;

    linked_strtab = (Elf64_Shdr *)((char *)nm->map_begin + nm->section_header_offset
        + (nm->section_header_size * cursor->sh_link));
    str_tab = (char *)nm->map_begin + linked_strtab->sh_offset;
    str_size = linked_strtab->sh_size;
    assign_sym_64(nm, cursor, str_tab);
}

int retrieve_symtab_intel_64(t_nm *nm)
{
    void        *cursor;
    Elf64_Shdr  *check;
    uint64_t    dec;

    cursor = nm->map_begin + nm->section_header_offset;
    dec = nm->section_header_nb;
    while (dec)
    {
        check = (Elf64_Shdr *)cursor;
        if (check->sh_type == SHT_SYMTAB)
            fetch_symtab_data_64(nm, check);
        --dec;
        cursor += nm->section_header_size;
    }
    return (0);
}

