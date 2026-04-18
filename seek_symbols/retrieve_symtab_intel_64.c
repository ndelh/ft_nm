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


void    print_sym_64(t_nm *nm, Elf64_Shdr *sym, char *s, uint64_t size)
{
    Elf64_Sym   *current_sym;
    uint64_t    it;
    
    (void)size;
    current_sym = (Elf64_Sym *)((char *)nm->map_begin + (sym->sh_offset));
    //printf("program size: %ld required offset:  %u\n", nm->stat->st_size, sym->sh_link);
    it = sym->sh_size / sym->sh_entsize;
    while (it)
    {
        printf("symbol adress: %zu symbol name: %s\n", current_sym->st_value, s + current_sym->st_name);
        --it;
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
    //print_strtab(str_tab, str_size);
    print_sym_64(nm, cursor, str_tab, str_size);
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

