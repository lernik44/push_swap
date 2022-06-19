# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmirzakh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 19:44:06 by lmirzakh          #+#    #+#              #
#    Updated: 2022/04/27 14:07:20 by lmirzakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
#AR		= ar rcs :commented out in case needed in future
RM		= rm -f

SRCS	=	$(wildcard *.c)
#SRCS_B	=	$(wildcard ft_lst*.c) :commented out for future needs
#SRCS	=	$(filter-out $(SRCS_B), $(SRCS_A)) :commented out for future needs

OBJS	=	$(patsubst %.c, %.o, $(SRCS))
#OBJS_B	=	$(patsubst %.c, %.o, $(SRCS_B)) :commented out for future needs

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) -o $(NAME)

#bonus:		$(NAME) $(OBJS_B)	:commented out for future needs
#			$(AR) $(NAME) $(OBJS_B)	:commented out for future needs

clean:		
			$(RM) $(OBJS) $(OBJS_B)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re #bonus :commented out for future needs
