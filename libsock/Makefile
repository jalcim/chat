#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 13:59:15 by nbahri            #+#    #+#              #
#    Updated: 2014/03/26 05:43:18 by jalcim           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_inet.a

SRC =	ft_inetaddr.c\
	ft_readfd.c\
	ft_reip.c\
	ft_rinetaddr.c\
	ft_sock.c\
	ft_sock_in_file.c\
	ft_strsplit.c\
	locate.c\
	servcom.c

SRCO = $(SRC:.c=.o)

SRCH = ft_inet.h

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -c $(SRC) -I includes
		ar rc $(NAME) $(SRCO)
		ranlib $(NAME)
clean:
		/bin/rm -f $(SRCO)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
