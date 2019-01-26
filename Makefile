# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybolles <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/17 21:19:53 by ybolles           #+#    #+#              #
#    Updated: 2019/01/26 20:55:11 by ybolles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
NAME = fillit
all : $(NAME)

$(NAME) : *.c
		gcc $(FLAGS) -c *.c libft/*.c
		rm -f main.o
		gcc $(FLAGS) main.c *.o -o $@
clean :
		rm -f *.o
		rm -f libft/*.o
fclean : clean
		rm -f *.o
		rm -f fillit
re : fclean all
