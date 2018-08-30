# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 13:40:11 by tbenedic          #+#    #+#              #
#    Updated: 2018/08/30 13:05:10 by tbenedic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
NAME2 = push_swap

SRCC = $(addsuffix .c, $(FUNCS))
SRCO = $(addsuffix .o, $(FUNCS_O))
FUNCS =	main_checker stack_basics display admin operations1 operations2 \
		operations3 operations_inline get_next_line/get_next_line
LIBFT = get_next_line/libft/libft.a
HEAD  = push.h

all: $(NAME) $(NAME2)

$(NAME):
	make -C get_next_line/libft
	gcc -Wall -Werror -Wextra $(SRCC) $(LIBFT) -o $(NAME)  

$(NAME2):
	make -C get_next_line/libft
	gcc -Wall -Werror -Wextra $(SRCC) $(LIBFT) -o $(NAME2)

local:
	gcc -Wall -Werror -Wextra $(SRCC) $(LIBFT) -o $(NAME)
	gcc -Wall -Werror -Wextra $(SRCC) $(LIBFT) -o $(NAME2)

check:
	gcc -Wall -Werror -Wextra $(SRCC) $(LIBFT) -o $(NAME)

push:
	gcc -Wall -Werror -Wextra $(SRCC) $(LIBFT) -o $(NAME2)

clean: libclean

fclean: clean libfclean
		rm -f $(NAME)
		rm -f $(NAME2)

libclean:
		@make clean -C ./get_next_line/libft/
libfclean:
		@make fclean -C ./get_next_line/libft/

re: fclean all
