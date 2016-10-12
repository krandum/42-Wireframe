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

SRC		= main.c wireframe.c parser.c
OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LIBFT	= ./libft/libft.a
FTINC	= -I ./libft
FTLINK	= -L ./libft -lft

LIBGFX	= ./libgfx/libgfx.a
GFXINC	= -I ./libgfx
GFXLINK	= -L ./libgfx -lgfx

LIBMLX	= ./minilibx/libmlx.a
MLXINC	= -I ./minilibx
MLXLINK	= -L ./minilibx -lmlx -framework OpenGL -framework AppKit

SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj $(NAME)

full: obj libft libgfx mlx $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CFLAGS) $(FTINC) $(GFXINC) $(MLXINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

libgfx: $(LIBGFX)

mlx: $(LIBMLX)

$(LIBFT):
	make -C ./libft

$(LIBGFX):
	make -C ./libgfx

$(LIBMLX):
	make -C ./minilibx

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(FTLINK) $(GFXLINK) $(MLXLINK)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

totalclean:
	rm -rf $(OBJDIR)
	make -C ./libft clean
	make -C ./libgfx clean
	make -C ./minilibx clean

totalfclean: totalclean
	rm -rf $(NAME)
	make -C ./libft fclean
	make -C ./libgfx fclean

re: fclean all

fullre: totalfclean libft libgfx mlx all
