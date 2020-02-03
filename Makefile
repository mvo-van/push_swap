# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/17 16:27:26 by mvo-van-          #+#    #+#              #
#    Updated: 2020/01/10 14:21:31 by mvo-van-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECK	 			=	checker
NAME_PUSH				=	push_swap
LIB						=	./libft/
SRC_CHECK				=	srcs/checker/checker.c		\
							srcs/checker/liste.c		\
							srcs/checker/make_instr.c	\
							srcs/checker/reduce.c		\
							srcs/checker/free.c			\
							srcs/checker/verif_instr.c

SRC_PUSH				=	srcs/push_swap/count.c		\
							srcs/push_swap/instr.c		\
							srcs/push_swap/list.c		\
							srcs/push_swap/make.c		\
							srcs/push_swap/opti.c		\
							srcs/push_swap/opti_mouv.c	\
							srcs/push_swap/print.c		\
							srcs/push_swap/push_swap.c	\
							srcs/push_swap/save.c		\
							srcs/push_swap/save_seul.c	\
							srcs/push_swap/test.c		\

OBJ_CHECK     			=	$(SRC_CHECK:.c=.o)
OBJ_PUSH     			=	$(SRC_PUSH:.c=.o)
CFLAGS		   			=	-Wall -Werror -Wextra -I includes

all : $(NAME_PUSH) $(NAME_CHECK)

$(NAME_PUSH): $(OBJ_PUSH)
	make -C $(LIB)
	gcc -o $(NAME_PUSH) $(OBJ_PUSH) $(CFLAGS) libft/libft.a

$(NAME_CHECK): $(OBJ_CHECK)
	gcc -o $(NAME_CHECK) $(OBJ_CHECK) $(CFLAGS) libft/libft.a

clean:
		make -C $(LIB) clean
	    rm -f $(OBJ_CHECK)
		rm -f $(OBJ_PUSH)
fclean: clean
		make -C $(LIB) fclean
	    rm -f $(NAME_CHECK)
		rm -f $(NAME_PUSH)
re: fclean all

.PHONY : all, $(NAME_CHECK), $(NAME_PUSH), clean, fclean, re