# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/09 18:06:54 by palatorr          #+#    #+#              #
#    Updated: 2016/10/09 18:06:55 by palatorr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

SRC		= main.c wireframe.c
OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LIBFT	= ./libft/libft.a
FTINC	= -I ./libft
FTLINK	= -L ./libft -lft

LIBMLX	= ./minilibx/libmlx.a
MLXINC	= -I ./minilibx
MLXLINK	= -L ./minilibx -lmlx -framework OpenGL -framework AppKit

SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj libft mlx $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) $(FTINC) $(MLXINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

mlx: $(LIBMLX)

$(LIBFT):
	make -C ./libft

$(LIBMLX):
	make -C ./minilibx

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(FTLINK) $(MLXLINK)

clean:
	rm -rf $(OBJDIR)
	make -C ./libft clean
	make -C ./minilibx clean

fclean: clean
	rm -rf $(NAME)
	make -C ./libft fclean

re: fclean all
