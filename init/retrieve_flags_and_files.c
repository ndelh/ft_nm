/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_flags_and_files.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 14:32:04 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/19 14:32:16 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int count_files(char **argv)
{
    int i;

    i = 0;
    while (*argv)
    {
        if (**argv != '-')
            ++i;
        ++argv;
    }
    return (i);
}

void    retrieve_files(t_nm *nm, char **argv)
{
    char **tab;

    tab = nm->files_to_nm;
    while (*argv)
    {
        if (**argv != '-')
        {
            *tab = *argv;
            ++tab;
        }
        ++argv;
    }
    *tab = 0;
}

int    active_flags(t_nm *nm, char *s)
{
        ++s;
        while (*s)
        {
            if (*s == 'a')
                nm->flags |= FLAG_a;
            else if (*s == 'g')
                nm->flags |= FLAG_g;
            else if (*s == 'u')
                nm->flags |= FLAG_u;
            else if (*s == 'r')
                nm->flags |= FLAG_r;
            else if (*s == 'p')
                nm->flags = FLAG_p;
            else
                return (unsupported_char(s));
            ++s;
        }
        return (0);
}



int    retrieve_flags(t_nm *nm, char **argv)
{
        while (*argv)
        {
            if (**argv == '-')
                if (active_flags(nm ,*argv))
                    return (1);
            ++argv;
        }
        return (0);
}

void    retrieve_flag_and_files(t_nm *nm, char **argv)
{

    nm->file_nb = count_files(argv + 1);
    nm->files_to_nm = malloc(sizeof(char *) * (nm->file_nb + 1));
    if (!nm->files_to_nm)
    {
        print_simple_error("malloc failed");
        return ;
    }
    retrieve_files(nm, argv + 1);
    if (retrieve_flags(nm, argv + 1))
        nm->must_exit = 0;
}
