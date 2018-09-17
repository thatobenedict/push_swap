# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 13:40:11 by tbenedic          #+#    #+#              #
#    Updated: 2018/09/16 09:04:12 by tbenedic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
NAME2 = push_swap

CHECK_SRC = $(addsuffix .c, $(CHECK_FUNC))
PUSH_SRC = $(addsuffix .c, $(PUSH_FUNC))
CHECK_FUNC = main_checker stack_basics display admin operations1 operations2 \
		operations3 operations_inline get_next_line/get_next_line
PUSH_FUNC = main_push stack_basics display admin operations1 operations2 \
		operations3 operations_inline get_next_line/get_next_line \
	   	algo algo2 algo3 algo3_helper do_ps1 do_ps2 do_ps3
LIBFT = get_next_line/libft/libft.a
HEAD  = push.h

all: $(NAME) $(NAME2)

$(NAME):
	make -S -C get_next_line/libft
	gcc -Wall -Werror -Wextra $(CHECK_SRC) $(LIBFT) -o $(NAME)  

$(NAME2):
	make -S -C get_next_line/libft
	gcc -Wall -Werror -Wextra $(PUSH_SRC) $(LIBFT) -o $(NAME2)

local:
	gcc -Wall -Werror -Wextra $(CHECK_SRC) $(LIBFT) -o $(NAME)
	gcc -Wall -Werror -Wextra $(PUSH_SRC) $(LIBFT) -o $(NAME2)

check:
	gcc -Wall -Werror -Wextra $(CHECK_SRC) $(LIBFT) -o $(NAME)

push:
	gcc -Wall -Werror -Wextra $(PUSH_SRC) $(LIBFT) -o $(NAME2)

clean: libclean

fclean: clean libfclean
		rm -f $(NAME)
		rm -f $(NAME2)

libclean:
		@make clean -C ./get_next_line/libft/
libfclean:
		@make fclean -C ./get_next_line/libft/

re: fclean all
