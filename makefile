# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 15:30:29 by gguidone          #+#    #+#              #
#    Updated: 2023/03/22 15:30:29 by gguidone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

NAME_BONUS	=	checker

SRC			=	check.c main.c moves.c little.c five.c r.c rr.c s.c hundred.c utilis.c setup.c lis.c
				
LIBFT		=	libft/libft.a

OBJ			=	$(SRC:.c=.o)

OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

CC			=	gcc 

RM			=	rm -f

CFLAGS		=	-g

$(NAME):	$(OBJ)
			make -C ./libft
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

all:		$(NAME)

clean:
			make clean -C libft
			${RM} $(OBJ) $(OBJ_BONUS)

fclean: 	clean
			make fclean -C libft
			${RM} $(NAME) $(NAME_BONUS) ${OBJ} $(OBJ_BONUS)

re:			fclean all

bonus:		all $(OBJ_BONUS)
			$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT)


.PHONY:		all clean fclean re