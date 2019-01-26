# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhourba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 15:42:37 by akhourba          #+#    #+#              #
#    Updated: 2018/10/16 08:01:58 by nhamid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror ft*.c
	ar rc libft.a ft*.o

clean:
	rm -rf ft*.o

fclean: clean
	rm -rf $(NAME)
re: fclean all
