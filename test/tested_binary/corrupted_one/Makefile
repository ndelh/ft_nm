# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 17:08:53 by ndelhota          #+#    #+#              #
#    Updated: 2026/05/02 19:09:49 by ndelhota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := corrupting

SRC := corruptor_core.c \
       open_map.c \
       go_to_elf_header.c \


CC := cc

CFLAGS := -g -Wall -Werror -Wextra

OBJDIR = obj
OBJ = $(SRC:.c=.o)
OBJ := $(addprefix $(OBJDIR)/, $(OBJ))

LIB := ../../lib/libft/libft.a \

all : $(LIB) $(OBJ) $(NAME)


$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME) -lreadline

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c -o $@ $^

$(LIB) :
	@make bonus -C ../../lib/libft

clean :
	@rm -rf $(OBJDIR) 
	@make -C ../../lib/libft clean

fclean : clean 
	@rm -f $(NAME)
	@make -C ../../lib/libft fclean

re : fclean all

copy : 
	cp ../../nm_tester nm_tester

.PHONY : all clean fclean re copy
