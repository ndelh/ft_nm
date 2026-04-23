# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 17:08:53 by ndelhota          #+#    #+#              #
#    Updated: 2026/04/20 19:15:15 by ndelhota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_nm 

SRC := main.c \
       retrieve_args/retrieve_args.c \
       retrieve_args/retrieve_flags.c \
       nm_core/nm_core.c \
	   nm_core/nm_utils/overflow_checker.c \
	   nm_core/nm_utils/range_checker.c \
       nm_core/nm_print/nm_print.c \
       nm_core/nm_init/nm_init.c \
	   nm_core/nm_init/retrieve_basics.c \
	   nm_core/nm_init/retrieve_basic_utils.c \
	   nm_core/nm_init/retrieve_shstr.c \
	   nm_core/retrieve_symbols/retrieve_symbols.c \
	   nm_core/retrieve_symbols/retrieve_symtab_intels.c \
       nm_core/end_nm/end_nm.c \
       end/end.c \

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
