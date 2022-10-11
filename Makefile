SRC_SEVER		=	server.c
SRC_CLIENT		=	client.c	\
					ft_atoi.c

OBJ_SEVER		=	$(SRC_SEVER:.c=.o)
OBJ_CLIENT		=	$(SRC_CLIENT:.c=.o)

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror

NAME			=	minitalk
NAME_SERVER		=	server
NAME_CLIENT		=	client

all:			$(NAME)

$(NAME):		$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):	$(OBJ_SEVER)
				$(CC) $(CFLAGS) $(OBJ_SEVER) -o $(NAME_SERVER)

$(NAME_CLIENT):	$(OBJ_CLIENT)
				$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)

re:				fclean all

clean:
				rm -f $(OBJ_SEVER) $(OBJ_CLIENT)

fclean:			clean
				rm -f $(NAME_SERVER) $(NAME_CLIENT)

.PHONY:			all re clean fclean
