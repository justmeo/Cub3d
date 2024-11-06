# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 13:07:02 by fmaqdasi          #+#    #+#              #
#    Updated: 2024/11/06 11:20:22 by fmaqdasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR				= ar rcs
RM				= rm -f

NAME			= get_next_line.a

FILES	=	get_next_line.c get_next_line_utils.C

OBJS	= $(addsuffix .o,$(basename $(FILES)))

all:			$(NAME)

$(NAME):		$(OBJS)
				$(AR) $(NAME) $(OBJS)

clean:			
				$(RM) $(OBJS) $(OBJSB)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME) bonus

bonus:			$(OBJSB) 
				$(AR) $(NAME) $(OBJSB) 

.PHONY:			all clean fclean re bonus