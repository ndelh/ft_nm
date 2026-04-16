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
       utils/print.c \
       utils/overflow_check.c \
       utils/out_of_bound_check.c \
       retrieve/retrieve.c \
       retrieve/retrieve_16_bytes.c \
       retrieve/retrieve_shstr_content.c \
       retrieve/fetch.c \
       seek_symbols/seek_symbols.c \
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
