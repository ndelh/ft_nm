# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 17:08:53 by ndelhota          #+#    #+#              #
#    Updated: 2026/04/16 12:59:51 by ndelhota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_nm 

SRC := main.c \
       init/init.c \
       init/init_utils.c \
       init/retrieve_flags_and_files.c \
       utils/print.c \
       utils/overflow_check.c \
       utils/out_of_bound_check.c \
       utils/display_result.c \
       retrieve/retrieve.c \
       retrieve/retrieve_16_bytes.c \
       retrieve/retrieve_shstr_content.c \
       retrieve/fetch.c \
       seek_symbols/seek_symbols.c \
       seek_symbols/safety_section_header_loop.c \
       seek_symbols/retrieve_symtab_intel_64.c \
       seek_symbols/parse_sh_link.c \
       seek_symbols/seek_symbols_utils.c \
       seek_symbols/list_add.c \
       end/end.c

CC := cc

CFLAGS := -g -Wall -Werror -Wextra

OBJDIR = obj
OBJ = $(SRC:.c=.o)
OBJ := $(addprefix $(OBJDIR)/, $(OBJ))

LIB := lib/libft/libft.a \

all : $(LIB) $(OBJ) $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME) -lreadline

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c -o $@ $^

$(LIB) :
	@make bonus -C lib/libft

clean :
	@rm -rf $(OBJDIR) 
	@make -C lib/libft clean

fclean : clean 
	@rm -f $(NAME)
	@make -C lib/libft fclean

re : fclean all

.PHONY : all clean fclean re
