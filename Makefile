# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 15:33:23 by fmaqdasi          #+#    #+#              #
#    Updated: 2024/11/09 15:33:25 by fmaqdasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = $(SRCDIR)/cub3d.c \
		$(SRCDIR)/util_map_render.c \
		$(SRCDIR)/util_map_render2.c \
		$(SRCDIR)/movement.c \
		$(SRCDIR)/movement2.c \
		$(SRCDIR)/util_main.c \
		$(SRCDIR)/util_main2.c \
		$(SRCDIR)/util_math.c \
		$(SRCDIR)/util_math2.c \
		$(SRCDIR)/util_mlx.c \
		$(SRCDIR)/util_map_parscing3.c \
		$(SRCDIR)/util_map_parscing2.c \
		$(SRCDIR)/util_map_parscing.c \
		$(SRCDIR)/free.c \
		$(SRCDIR)/free2.c \
		$(SRCDIR)/inti.c \
		$(SRCDIR)/util_casting.c \
		$(SRCDIR)/util_math_dda.c \


		

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
	@make -C libft
	@make -C get_next_line
	@make -C $(MLXDIR)
	@$(CC) $(OBJS) $(CFLAGS) -L$(MLXDIR) -lmlx -lm -march=native $(MLXFLG) -o $(NAME) $(LIB) $(GNL)

clean:
	@rm -rf $(OBJS) $(BONUS_OBJS) $(OBJDIR) $(B_OBJDIR)
	@make clean -C libft
	@make clean -C get_next_line
	@make clean -C $(MLXDIR)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUSNAME)
	@rm -f libft/libft.a
	@rm -f get_next_line/get_next_line.a

re: fclean all
