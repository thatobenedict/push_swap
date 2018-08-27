# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 13:40:11 by tbenedic          #+#    #+#              #
#    Updated: 2018/08/27 12:22:09 by tbenedic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRCC = $(addsuffix .c, $(FUNCS))
SRCO = $(addsuffix .o, $(FUNCS_O))
FUNCS =	main_checker stack_basics display admin operations1
LIBFT = get_next_line/libft/libft.a
HEAD  = push.h

all: $(NAME)

$(NAME):
	make -C get_next_line/libft
#	gcc -Wall -Werror -Wextra -c $(SRCC)
	gcc -Wall -Werror -Wextra $(SRCC) $(LIBFT) -o $(NAME)  

local:
	gcc -Wall -Werror -Wextra $(SRCC) $(LIBFT) -o $(NAME) 

clean: libclean
#		rm -f $(SRCO)

fclean: clean libfclean
		rm -f $(NAME) 

libclean:
		@make clean -C ./get_next_line/libft/
libfclean:
		@make fclean -C ./get_next_line/libft/

re: fclean all
