# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/02 22:13:13 by jadithya          #+#    #+#              #
#    Updated: 2024/11/06 14:04:01 by fmaqdasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = $(SRCDIR)/cub3d.c \
		$(SRCDIR)/casting.c \
		$(SRCDIR)/DDA.c \
		$(SRCDIR)/drawing.c \
		$(SRCDIR)/error.c \
		$(SRCDIR)/free_parsing.c \
		$(SRCDIR)/keypress.c \
		$(SRCDIR)/map_more.c \
		$(SRCDIR)/map_more2.c \
		$(SRCDIR)/map_more3.c \
		$(SRCDIR)/map_utils.c \
		$(SRCDIR)/map_valid.c \
		$(SRCDIR)/map.c \
		$(SRCDIR)/move.c \
		$(SRCDIR)/some_map.c \
		$(SRCDIR)/window_management.c \

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3

OS:= ${shell uname}
ifeq (${OS},Darwin)
	MLXDIR = mlx
	MLXFLG = -framework OpenGL -framework Appkit
	CFLAGS += -D OSX
else
	MLXDIR = mlx-linux
	MLXFLG = -lXext -lX11
	CFLAGS += -D LINUX
 endif

SRCDIR = srcs

OBJDIR = objs


OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

LIB = libft/libft.a
GNL = get_next_line/get_next_line.a

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I$(MLXDIR) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)


$(NAME): $(OBJDIR) $(OBJS)
	make -C libft
	make -C get_next_line
	make -C $(MLXDIR)
	$(CC) $(OBJS) $(CFLAGS) -L$(MLXDIR) -lmlx -lm -march=native $(MLXFLG) -o $(NAME) $(LIB) $(GNL)

clean:
	rm -rf $(OBJS) $(BONUS_OBJS) $(OBJDIR) $(B_OBJDIR)
	make clean -C libft
	make clean -C get_next_line
	make clean -C $(MLXDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUSNAME)
	rm -f libft/libft.a
	rm -f get_next_line/get_next_line.a

re: fclean all