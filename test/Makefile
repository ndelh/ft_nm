# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 17:08:53 by ndelhota          #+#    #+#              #
#    Updated: 2026/04/28 17:36:38 by ndelhota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := nm_tester 

SRC := main.c \
       init/init.c \
       init/gen_standard_file_list.c \
       init/gen_standard_test_list.c \
       init/gen_func_tab.c \
       init/gen_flag_tab.c \
       utils/tab_utils.c \
       utils/list_utils.c \
       test_core/tester_core.c \
       test_core/standard/standard_test.c \
       test_core/fork/true_nm_fork.c \
       test_core/fork/diff_popen_read.c \
       test_core/fork/my_nm_fork.c \
       test_core/test_utils/manage_doc.c \
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
