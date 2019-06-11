# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnightwi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/11 16:33:54 by dnightwi          #+#    #+#              #
#    Updated: 2019/06/11 16:33:59 by dnightwi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OUT = fillit
SRCS = srcs/*.c
HEAD = include/
MYLIB = libft/

all: $(OUT)
$(OUT):
	make -C $(MYLIB)
	gcc -Wall -Wextra -Werror $(SRCS) -I $(HEAD) -L $(MYLIB) -lft -o $(OUT)
clean:
	make fclean -C $(MYLIB)
fclean: clean
	rm -rf $(OUT)
re: fclean all