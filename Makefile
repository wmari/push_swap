# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmari <wmari@42.student.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 14:52:16 by wmari             #+#    #+#              #
#    Updated: 2022/03/30 11:12:39 by wmari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCSDIR	=	srcs

OBJSDIR	=	objs

SRCS	=	$(wildcard $(SRCSDIR)/*.c)

OBJS	=	$(SRCS:$(SRCSDIR)/%.c=$(OBJSDIR)/%.o)

HEADERS	=	header

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

all		:	$(NAME)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c | $(OBJSDIR)
			$(CC) $(CFLAGS) -c $< -o $@
$(OBJSDIR)	:	
				mkdir -p objs
$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -I $(HEADERS) -o $@	$(OBJS)

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all
