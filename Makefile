# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 23:15:25 by fmarsha           #+#    #+#              #
#    Updated: 2022/06/29 23:15:25 by fmarsha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	fractol

SRCS =	fractol.c hook.c sets.c get_frac.c init.c
OBJS = 	$(SRCS:.c=.o)

HEAD =	fractol.h mlx_keycode.h

CC = 	cc
FLAGS = -Wall -Wextra -Werror
RM = 	rm -f

all:	$(NAME)

run: $(NAME)
	@./$(NAME) julia1
	leaks --atExit -- ./$(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -lm -o $(NAME)


bonus: $(NAME)

.c.o: $(HEAD)
	$(CC) $(FLAGS) -Imlx  -c $< -o $(<:.c=.o)

clean:
	${RM} ${OBJS} $(B_OBJS)

fclean: clean
	$(RM) $(NAME) $(B_NAME)

re: fclean all

.PHONY: all clean fclean re bonus