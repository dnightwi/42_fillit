# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnightwi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/11 16:33:54 by dnightwi          #+#    #+#              #
#    Updated: 2019/06/13 16:49:57 by rsticks          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = srcs/*.c
HEAD = include/
MYLIB = libft/

all: $(NAME)
$(NAME):
	make -C $(MYLIB)
	gcc -Wall -Wextra -Werror $(SRCS) -I $(HEAD) -L $(MYLIB) -lft -o $(NAME)
clean:
	make fclean -C $(MYLIB)
fclean: clean
	rm -rf $(NAME)
re: fclean all
