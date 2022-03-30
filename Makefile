# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmari <wmari@42.student.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 14:52:16 by wmari             #+#    #+#              #
#    Updated: 2022/03/30 11:49:47 by wmari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCSDIR	=	srcs

OBJSDIR	=	objs

SRCS	=	srcs/back_to_a.c\
			srcs/back_to_start.c\
			srcs/back_to_start_b.c\
			srcs/create_stack.c\
			srcs/deal_with_arg.c\
			srcs/identity.c\
			srcs/identity_2.c\
			srcs/identity_cont.c\
			srcs/parsing.c\
			srcs/push.c\
			srcs/push_swap.c\
			srcs/revrot.c\
			srcs/rot.c\
			srcs/smart_back.c\
			srcs/smart_push.c\
			srcs/sort_alg.c\
			srcs/swap.c

OBJS	=	$(SRCS:$(SRCSDIR)/%.c=$(OBJSDIR)/%.o)

HEADERS	=	header

CC		=	cc

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
			rm -rf objs

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all
